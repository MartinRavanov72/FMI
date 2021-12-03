function unique(arr, cmp) {
    let res = [];

    arr.reduce(function (acc, curr) {
        if (cmp(acc, curr) !== 0) {
            res.push(curr);
        }

        return curr;
    }, arr[0]);

    return res;
}