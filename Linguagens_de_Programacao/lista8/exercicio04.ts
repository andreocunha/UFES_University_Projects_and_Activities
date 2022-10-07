"use strict";

class Forma {
    calculaPerimetro: () => number;
    calculaArea: () => number;
    constructor() {
        if (this.calculaPerimetro === undefined) {
            throw new TypeError("calculaPerimetro deve ser implementado");
        }
	
        if (this.calculaArea === undefined) {
            throw new TypeError("calculaArea deve ser implementado");
        }
    }
}

class Quadrilatero extends Forma {
    lados: number[];
    constructor(l1:number, l2:number, l3:number, l4:number) {
        super();
        
        if (this.constructor === Quadrilatero) {
            throw new TypeError("Quadrilatero deve ser instanciado com new");
        }
        
        this.lados = [l1, l2, l3, l4];
    }
    
    calculaPerimetro = () => {
        return this.lados.reduce((a, b) => a + b, 0);
    }
}

class Retangulo extends Quadrilatero {

    constructor(base:number, altura:number) {
        super(base, altura, base, altura);
    }
    
    get base() {
        return this.lados[0];
    }
    
    get altura() {
        return this.lados[1];
    }
    
    calculaArea = () => {
        return this.base * this.altura;
    }
    
    toString() {
        return `Retângulo de base ${this.base} e altura ${this.altura}:\n` +
               `\tPerímetro = ${this.calculaPerimetro()}\n` +
               `\tÁrea = ${this.calculaArea()}\n`;   
    }
}

class Quadrado extends Retangulo {
    constructor(lado:number) {
        super(lado, lado);
    }
    
    get lado() {
        return this.lados[0];
    }
    
    toString() {
        return `Quadrado de lado ${this.lado}:\n` +
               `\tPerímetro = ${this.calculaPerimetro()}\n` +
               `\tÁrea = ${this.calculaArea()}\n`;   
    }
}

class Circulo extends Forma {
    raio:number;
    constructor(raio:number) {
        super();
        this.raio = raio;
    }
    
    calculaPerimetro = () => {
        return 2 * Math.PI * this.raio;
    }
    
    calculaArea = () => {
        return Math.PI * this.raio * this.raio;
    }
    
    toString() {
        return `Circulo de raio ${this.raio}:\n` + 
                `\tPerímetro = ${this.calculaPerimetro()}\n` +
                `\tÁrea = ${this.calculaArea()}\n`; 
    }
}

let formas: Forma[] = [];
formas.push( new Quadrado(4.0) );
formas.push( new Retangulo(2.5, 6.0) );
formas.push( new Circulo(3.0) );
