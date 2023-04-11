const V = ['0', '2', '5', '13'];

function addNumber(a, b) {
  let A = a.split('').reverse();
  let B = b.split('').reverse();
  let C = '';
  let D = 0;
  for (let i = 0; i < Math.max(A.length, B.length); i++) {
    let M = (+A[i] || 0) + (+B[i] || 0) + D;
    D = Math.floor(M / 10);
    C += (M % 10).toString();
  }
  if (D) {
    C += D.toString();
  }
  return C.split('').reverse().join('');
}

function countNumbers() {
  for (let i = 4; ; i++) {
    let C = addNumber(V[i - 1], V[i - 1]);
    C = addNumber(V[i - 2], C);
    C = addNumber(V[i - 3], C);
    V.push(C);
    if (V[i].length > 1001) {
      break;
    }
  }
}

function inputOutput() {
  countNumbers();
  let N;
  while (true) {
    N = parseInt(prompt('Введите число N:'));
    if (isNaN(N)) {
      break;
    }
    console.log('N: ' + N);
    console.log('Результат: ' + V[N]);
  }
}

inputOutput();
