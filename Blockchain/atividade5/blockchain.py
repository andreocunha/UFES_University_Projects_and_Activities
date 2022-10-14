# André Oliveira Cunha - Engenharia de Computação - UFES

import datetime
import json
import hashlib
from flask import Flask, jsonify


class Blockchain:
    def __init__(self):
        self.chain = []
        self.create_blockchain(proof=1, previous_hash='0')

    def create_blockchain(self, proof, previous_hash):
        block = {
            'index': len(self.chain) + 1,
            'timestamp': str(datetime.datetime.now()),
            'proof': proof,
            'previous_hash': previous_hash
        }

        self.chain.append(block)
        return block

    def get_previous_block(self):
        last_block = self.chain[-1]
        return last_block

    def proof_of_work(self, previous_proof):
        # variavel para armazenar o proof of work
        new_proof = 1
        # variavel para o estado de verificação do proof of work
        check_proof = False

        # loop para a mineração
        while check_proof is False:
            # definicao do problema e algoritmo baseado no proof of work anterior e no novo proof of work
            hash_operation = hashlib.sha256(str(new_proof ** 2 - previous_proof ** 2).encode()).hexdigest()
            # verificacao se o hash gerado tem 6 zeros no inicio
            # se tiver, o proof of work foi encontrado e o loop é quebrado
            if hash_operation[:6] == '000000':
                check_proof = True
            else:
                # se o proof of work nao foi encontrado, incrementa o valor do proof of work
                new_proof += 1
        # retorna o novo proof of work
        return new_proof

    # cria uma hash do bloco inteiro
    def hash(self, block):
        encoded_block = json.dumps(block, sort_keys=True).encode()
        return hashlib.sha256(encoded_block).hexdigest()

    # verifica se o blockchain é valido
    def is_chain_valid(self, chain):
        # pega o primeiro bloco da blockchain
        previous_block = chain[0]
        # variavel para iterar os blocos da blockchain
        block_index = 1
        while block_index < len(chain):
            # pega o bloco atual
            block = chain[block_index]
            # verifica se o hash do bloco anterior é igual ao hash do bloco atual
            if block["previous_hash"] != self.hash(previous_block):
                return False

            # pega o proof of work do bloco anterior
            previous_proof = previous_block['proof']

            # pega o proof of work do bloco atual
            current_proof = block['proof']

            # executa a informacao do proof of work no algoritmo
            hash_operation = hashlib.sha256(str(current_proof ** 2 - previous_proof ** 2).encode()).hexdigest()
            # se o hash gerado nao tiver 6 zeros no inicio, o bloco é invalido
            if hash_operation[:6] != '000000':
                return False
            # define o bloco anterior como o bloco atual depois de validar o bloco atual
            previous_block = block
            # incrementa o index do bloco
            block_index += 1
        return True


app = Flask(__name__)

blockchain = Blockchain()

@app.route('/mine_block', methods=['GET'])
def mine_block():
    # pega a informacao necessaria para criar um bloco
    previous_block = blockchain.get_previous_block()
    previous_proof = previous_block['proof']
    proof = blockchain.proof_of_work(previous_proof)
    previous_hash = blockchain.hash(previous_block)

    block = blockchain.create_blockchain(proof, previous_hash)
    response = {'message': 'Block mined!',
                'index': block['index'],
                'timestamp': block['timestamp'],
                'proof': block['proof'],
                'previous_hash': block['previous_hash']}
    return jsonify(response), 200

# resonsavel por retornar a blockchain em formato json
@app.route('/get_chain', methods=['GET'])
def get_chain():
    response = {'chain': blockchain.chain,
                'length': len(blockchain.chain)}
    return jsonify(response), 200


app.run(host='0.0.0.0', port=4000)