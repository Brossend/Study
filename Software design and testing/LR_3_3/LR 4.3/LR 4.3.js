const countBlock = prompt('Введите количество блоков!');

console.log(countBlock);

for (let i = 0; i < countBlock; i++) {
  let countOrders = prompt('Введите число заказов!');

  console.log(countOrders);

  if (countOrders > 1000 || countOrders < 1) {
    break;
  }

  const arrayTerm = [];
  const arrayFine = [];
  const arrayRatio = [];
  const arrayRatioTemp = [];
  const arrayResult = [];

  for (let i = 0; i < countOrders; i++) {
    arrayTerm[i] = prompt(`Введите срок заказа №${i + 1}!`);
    arrayFine[i] = prompt(`Введите штраф за заказ №${i + 1}!`);

    arrayRatio[i] = arrayTerm[i] / arrayFine[i];
    arrayRatioTemp[i] = arrayTerm[i] / arrayFine[i];
  }

  arrayRatioTemp.sort(function (a, b) {
    return a - b;
  });

  console.log('Result');

  for (let i = 0; i < arrayRatioTemp.length; i++) {
    for (let j = 0; j < arrayRatio.length; j++) {
      if (arrayRatioTemp[i] === arrayRatio[j]) {
        if (!arrayResult.includes(j)) {
          arrayResult[i] = j;
          console.log(j + 1);
          break;
        }
      }
    }
  }
}
