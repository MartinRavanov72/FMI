function divide(list, fn) {
    return list.reduce(function (acc, curr) {
        acc[fn[curr] ? 0 : 1].push(curr);
        return acc;
    }, [[], []])
}