function findMinStations(N, roads) {
  let nodes = new Array(N).fill(0);
  for (let i = 0; i < roads.length; i++) {
    let a = roads[i][0] - 1;
    let b = roads[i][1] - 1;
    nodes[a]++;
    nodes[b]++;
  }
  let max = 0;
  for (let i = 0; i < N; i++) {
    if (nodes[i] > max) {
      max = nodes[i];
    }
  }
  return Math.max(max, 1);
}

// Пример использования
let N = 5;
let roads = [
  [1, 2],
  [2, 3],
  [3, 4],
  [4, 5],
  [5, 1],
];

console.log(findMinStations(N, roads)); // Вывод: 2
// В этом случае две станции техобслуживания достаточно:
// одна на городе 1, а другая на городе 3 или 5.
