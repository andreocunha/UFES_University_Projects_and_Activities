// Andre Oliveira Cunha
const prompt = require('prompt-sync')();

// 1 )
function tempo(tempoSegundos) {
  tempoSegundos = parseFloat(tempoSegundos);
  let horas = Math.floor(tempoSegundos / 3600);
  let minutos = Math.floor((tempoSegundos % 3600) / 60);
  let segundos = tempoSegundos % 60;
  return `${horas}h ${minutos}m ${segundos}s`;
}
let numeroConvertido = prompt("Digite um numero em segundos: ");
console.log(tempo(numeroConvertido));

// 2 )
function baskara(a, b, c) {
  let delta = Math.pow(b, 2) - 4 * a * c;
  if (delta < 0) {
    return "Não possui raízes reais";
  } else if (delta == 0) {
    return -b / (2 * a);
  } else {
    return (-b + Math.sqrt(delta)) / (2 * a);
  }
}

// 3 )
function media(nota1, nota2, nota3) {
  // converte para numero
  nota1 = parseFloat(nota1);
  nota2 = parseFloat(nota2);
  nota3 = parseFloat(nota3);
  let media = (nota1 + nota2 + nota3) / 3;
  if (media >= 7) {
    return "Aprovado";
  } else if (media >= 5 && media < 7) {
    return "Recuperação";
  } else {
    return "Reprovado";
  }
}
let mediaCalculada = media(prompt("Digite a primeira nota: "), prompt("Digite a segunda nota: "), prompt("Digite a terceira nota: "));
console.log(mediaCalculada);


// 4 )
function peso(peso, numPlaneta) {
  let pesoPlaneta = 0;
  switch (Number(numPlaneta)) {
    case 1:
      pesoPlaneta = peso * 0.37;
      break;
    case 2:
      pesoPlaneta = peso * 0.88;
      break;
    case 3:
      pesoPlaneta = peso * 0.38;
      break;
    case 4:
      pesoPlaneta = peso * 2.64;
      break;
    case 5:
      pesoPlaneta = peso * 1.15;
      break;
    case 6:
      pesoPlaneta = peso * 1.17;
      break;
    case 7:
      pesoPlaneta = peso * 1.18;
      break;
    default:
      pesoPlaneta = "Planeta invalido";
  }
  return pesoPlaneta;
}
let pesoPlaneta = peso(prompt("Digite o peso em Newtons: "), prompt("Digite o numero do planeta: "));
console.log(pesoPlaneta);

// 5 )
function tabelaCelsius() {
  let celsius = -100;
  while (celsius <= 100) {
    let fahrenheit = celsius * 9 / 5 + 32;
    console.log(celsius + " oC = " + fahrenheit + " oF");
    celsius += 5;
  }
}

// 6 )
function cosseno(x) {
  let soma = 0;
  let termo = 1;
  let i = 0;
  while (i < 20) {
    termo = Math.pow(-1, i) * Math.pow(x, 2 * i) / (2 * i + 1);
    soma += termo;
    i++;
  }
  return soma;
}

// 7 )
function fibonnacci(n) {
  let termo1 = 0;
  let termo2 = 1;
  let termo3 = 0;
  let i = 0;
  while (i < n) {
    termo3 = termo1 + termo2;
    termo1 = termo2;
    termo2 = termo3;
    i++;
  }
  return termo3;
}