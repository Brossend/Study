const matrix = [
  [3, 4, 1, 2, 8, 6],
  [6, 1, 8, 2, 7, 4],
  [5, 9, 3, 9, 9, 5],
  [8, 4, 1, 3, 2, 6],
  [3, 7, 2, 8, 6, 4],
];

/* const matrix = [
  [3, 4, 1, 2, 8, 6],
  [6, 1, 8, 2, 7, 4],
  [5, 9, 3, 9, 9, 5],
  [8, 4, 1, 3, 2, 6],
  [3, 7, 2, 1, 2, 3],
]; */

const rows = matrix.length;
const columns = matrix[0].length;

const costs = matrix.map((row) => [...row]);

for (let j = 1; j < columns; j++) {
  for (let i = 0; i < rows; i++) {
    const up = costs[(i - 1 + rows) % rows][j - 1];
    const left = costs[i][j - 1];
    const down = costs[(i + 1) % rows][j - 1];

    const minCost = Math.min(up, left, down);

    costs[i][j] += minCost;
  }
}

let minCost = costs[0][columns - 1];
let minRow = 0;

for (let i = 1; i < rows; i++) {
  if (costs[i][columns - 1] < minCost) {
    minCost = costs[i][columns - 1];
    minRow = i;
  }
}

let path = [minRow];

for (let j = columns - 1; j > 0; j--) {
  const up = costs[(minRow - 1 + rows) % rows][j - 1];
  const left = costs[minRow][j - 1];
  const down = costs[(minRow + 1) % rows][j - 1];

  const minCost = Math.min(up, left, down);

  if (minCost === up) {
    minRow = (minRow - 1 + rows) % rows;
  } else if (minCost === down) {
    minRow = (minRow + 1) % rows;
  }

  path.unshift(minRow);
}

console.log(`Путь: ${path.join(' - ')}`);
console.log(`Минимальный путь: ${minCost}`);
