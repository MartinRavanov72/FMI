function smallestElements(arr, cmp) {
    return arr.reduce(function (acc, curr) {
        var res = cmp(acc, curr);
        if (res > 0) {
            return curr;
        }

        return acc;
    }, arr[0]);
}