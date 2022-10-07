"use strict";

function print2d(matrix: Number[][]) {
    for (let line of matrix) {
        console.log(line.join(' '));
    }
}

function normalise2d(matrix: any[]) {
    let values = matrix.flat();
    let max = Math.max(...values);
  
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[i].length; j++) {
            matrix[i][j] /= max;
        }
    }
}

let number1:Number[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
normalise2d(number1);
print2d(number1);

console.log("teste");

let number2:Number[][] = [[3, 5], [6, 8]];
normalise2d(number2);
print2d(number2);
