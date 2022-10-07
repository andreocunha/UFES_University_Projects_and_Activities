"use strict";

class ContaCorrente {
    _saldo:number;
    
    constructor() {
        this._saldo = 0;
    }
    
    get saldo() {
        return this._saldo;
    }
    
    set saldo(valor) {
        if (valor < 0) {
            console.log("ERRO: o saldo esta negativo!");
            this._saldo = 0;
            return;
        }
        this._saldo = valor;
    }
    
    exibeSaldo() {
        console.log( `Saldo = ${this._saldo}` );
    }
}

class ContaEspecial extends ContaCorrente {
    get saldo() {
        return this._saldo;
    }
    
    set saldo(valor) {
        if (valor < 0) {
            console.log("Saldo negativo, aplicado taxa de operação.");
            this._saldo = 1.01 * valor;
            return;
        }
        this._saldo = valor;
    }
}

console.log( "Conta corrente: " );
let conta_corrente = new ContaCorrente();
conta_corrente.exibeSaldo();
conta_corrente.saldo = 4000;
conta_corrente.exibeSaldo();
conta_corrente.saldo -= 3000;
conta_corrente.exibeSaldo();


console.log( "\nConta especial: " );
let conta_especial = new ContaEspecial();
conta_especial.exibeSaldo();
conta_especial.saldo = 3000;
conta_especial.exibeSaldo();
conta_especial.saldo -= 1000;
conta_especial.exibeSaldo();
conta_especial.saldo += 1500;
conta_especial.exibeSaldo();
