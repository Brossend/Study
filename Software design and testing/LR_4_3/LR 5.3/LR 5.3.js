function NumberDigits(n) {
  if (n < 0 || n > 10000) {
    return false;
  } else {
    let number = 1;
    let char = '1';

    while (number % n !== 0) {
      char += '1';
      number = parseInt(char);
    }

    return char.length;
  }
}

// Тест
//Входные: 3, 7, 9901
console.log(NumberDigits(3)); // 3
console.log(NumberDigits(7)); // 6
console.log(NumberDigits(9901)); // 12
console.log(NumberDigits(10001)); // false
console.log(NumberDigits(-1)); // false
