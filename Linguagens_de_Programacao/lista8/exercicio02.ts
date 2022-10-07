"use strict";

interface IComplex {
    r:number,
    i:number,
}

class Complex {
    r: number;
    i: number;
    static ZERO: Complex;
    static ONE: Complex;
    static I: Complex;
    
    constructor(real: number, imaginary:number) {
        this.r = real;
        this.i = imaginary;
    }
    
    plus(that:IComplex):Complex {
        return new Complex(this.r + that.r, this.i + that.i);
    }

    times(that:IComplex):Complex {
        return new Complex(this.r * that.r - this.i * that.i, this.r * that.i + this.i * that.r);
    }

    static sum(c:Complex, d:Complex)     { return c.plus(d); }
    static product(c:Complex, d:Complex) { return c.times(d); }

    get real()      { return this.r; }
    get imaginary() { return this.i; }
    get magnitude() { return Math.hypot(this.r, this.i); }

    toString() { return `{${this.r},${this.i}}`; }
}

Complex.ZERO = new Complex(0,0);
Complex.ONE  = new Complex(1,0);
Complex.I    = new Complex(0,1);


let c:Complex = new Complex(2, 3);
let d:Complex = new Complex(c.i, c.r);
console.log( c.plus(d).toString() );
console.log( c.magnitude );
console.log( Complex.product(c, d) );
console.log( Complex.ZERO.toString() );
