const alphabet = {
  a: 'x',
  v: 'n',
  l: 'b',
  b: 'k',
  e: 'u',
  v: 'n',
  t: 'o',
  z: 'w',
  u: 'i',
  d: 's',
  x: 't',
  n: 'h',
  m: 'e',
  g: 'm',
  i: 'f',
  r: 'r',
  p: 'a',
  y: 'l',
  j: 'g',
  k: 'd',
  o: 'c',
  f: 'p',
  q: 'y',
  c: 'q',
  h: 'j',
  s: 'v',
  w: 'z',
  ' ': ' ',
};

const countBlock = prompt('Введите количество блоков!');

console.log(countBlock);
console.log(' ');

for (let i = 0; i < countBlock; i++) {
  for (let i = 0; i < 101; i++) {
    if (i === 100) {
      console.log('Not solution');
    } else {
      let code = prompt('Введите зашифрованное сообщение!');
      let codeArray = code.split('');

      if (codeArray.length > 80) {
        console.log('Not solution');
      } else if (code === '') {
        break;
      } else {
        let checkSolution = true;
        let result = '';

        for (let keyCode in codeArray) {
          for (let key in alphabet) {
            if (codeArray[keyCode] === key) {
              result += alphabet[key];
              checkSolution = true;
              break;
            } else {
              checkSolution = false;
            }
          }
          if (!checkSolution) {
            console.log('Not solution');
            break;
          }
        }

        if (checkSolution) {
          console.log(result);
        }
      }
    }
  }
  console.log(' ');
}

// vtz ud xnm xugm itr pyy jttk gmv xt otgm xt xnm puk ti xnm fprxq
// xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
// frtjrpgguvj otvxmdxd prm iev prmvx xnmq
