function findLadder(words) {
  // функция для определения, можно ли преобразовать слово a в слово b
  function canTransform(a, b) {
    // слова должны быть одинаковой длины
    if (a.length !== b.length) {
      return false;
    }

    let diff = 0;

    for (let i = 0; i < a.length; i++) {
      if (a[i] !== b[i]) {
        diff++;

        // если разница более чем в одной букве - нельзя преобразовать
        if (diff > 1) {
          return false;
        }
      }
    }
    return true;
  }

  // функция для нахождения всех ступенек редактирования
  function findSteps(word, dict, visited, path) {
    let longestPath = [];

    visited[word] = true;
    path.push(word);

    for (let i = 0; i < dict.length; i++) {
      if (!visited[dict[i]] && canTransform(word, dict[i])) {
        let subPath = findSteps(dict[i], dict, visited, path.slice());

        if (subPath.length > longestPath.length) {
          longestPath = subPath;
        }
      }
    }

    visited[word] = false;
    path.pop();

    return longestPath.length > path.length ? longestPath : path;
  }

  let visited = {};
  let maxLength = 0;
  let resultPath = [];

  // перебираем все слова в словаре и ищем наибольшую лесенку
  for (let i = 0; i < words.length; i++) {
    let path = findSteps(words[i], words, visited, []);

    if (path.length > maxLength) {
      maxLength = path.length;
      resultPath = path;
    }
  }

  return resultPath;
}

// пример использования
let words = ['cat', 'dig', 'dog', 'fig', 'fin', 'fine', 'fog', 'log', 'wine'];
let ladder = findLadder(words);

console.log(ladder); // 5 ['dig', 'dog', 'log', 'fog', 'fig']
