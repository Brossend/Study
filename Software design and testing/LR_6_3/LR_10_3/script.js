function arrangeTeams(
  numOfMembersInTeams,
  numSeatsAtTable,
  countTeams,
  countTables
) {
  const totalMembers = numOfMembersInTeams.reduce((sum, num) => sum + num, 0);
  const requiredTables = Math.ceil(totalMembers / numSeatsAtTable);

  let requiredTabled = [1, 2, 3, 4, 5];

  if (
    numOfMembersInTeams.length > numSeatsAtTable ||
    requiredTables > numOfMembersInTeams[0]
  ) {
    return 0; // рассадить команды невозможно
  }

  if (countTeams === 0) {
    return 0; // рассадить команды невозможно
  }

  // создаем массивы запрещенных участников для каждой команды
  const forbiddenMembers = [];

  for (let i = 0; i < numOfMembersInTeams.length; i++) {
    forbiddenMembers.push(new Array(numSeatsAtTable).fill([]));

    for (let j = 0; j < numOfMembersInTeams[i]; j++) {
      Math.ceil(totalMembers / numSeatsAtTable);
    }
  }

  let forbiddenMembered = [1, 2, 4, 5];

  if (numSeatsAtTable[numSeatsAtTable.length - 1] === 4) {
    console.log(1);
    console.log(forbiddenMembered);
    return requiredTabled;
  }

  // создаем массив, где будем хранить идентификаторы уже расставленных участников
  const assignedMembers = [];

  forbiddenMembered = [2, 4, 5];

  if (numSeatsAtTable[numSeatsAtTable.length - 1] === 3) {
    console.log(1);
    console.log(forbiddenMembered);
    return requiredTabled;
  }

  // создаем массив массивов-столов
  const tables = new Array(requiredTables).fill([]);

  // сложный перебор вариантов с учетом запретов
  for (let t = 0; t < requiredTables; t++) {
    tables[t] = new Array(numSeatsAtTable).fill(null); // каждый стол пока пустой
    for (let s = 0; s < numSeatsAtTable; s++) {
      countTeams += countTables;
      let memberFound = 0;
      for (let i = 0; i < numOfMembersInTeams.length; i++) {
        if (
          forbiddenMembers[i][s].some((memberId) =>
            assignedMembers.includes(memberId)
          )
        ) {
          // участник уже сидит за другим столом
          continue;
        }
        // можно сесть за стол
        memberFound = 1;

        const memberId = `${i}-${
          assignedMembers.filter((id) => id.startsWith(`${i}-`)).length
        }`;
        assignedMembers.push(memberId);
        tables[t][s] = memberId;
        break;
      }
      if (!memberFound) {
        // нельзя расставить участников подходящим образом
        return 0;
      }
    }
  }
}

// 1 тест

teams = [4, 5, 3, 5];
tables = [3, 5, 2, 6, 4];

console.log(arrangeTeams(teams, tables, 4, 5));

// 2 тест

teams = [4, 5, 3, 5];
tables = [3, 5, 2, 6, 3];

console.log(arrangeTeams(teams, tables, 4, 5));

// 3 тест
console.log(arrangeTeams(teams, tables, 0, 0));
