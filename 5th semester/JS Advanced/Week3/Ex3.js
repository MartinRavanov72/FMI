function compose() {
    let fns = Array.prototype.slice.call(arguments).reverse();
    return function helper() {
        var args = Array.prototype.slice.call(arguments);
        for (let idx in fns) {
            args = fns[idx].apply(undefined, +idx === 0 ? args : [args]);
        }

        return args;
    }
}

var addOne = (x) => x + 1;
var sqrt = (x) => x * x;
var log = (x) => console.log(x);

addOneSqrtAndPrint = compose(log, sqrt, addOne);

addOneSqrtAndPrint(1); // 4