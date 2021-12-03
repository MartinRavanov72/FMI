function curry(fn) {
    return function curried() {
        let args = Array.prototype.slice.call(arguments);
        if (args.length >= fn.length) {
            return fn.apply(this, args);
        }

        return function () {
            let args2 = args.concat(Array.prototype.slice.call(arguments));
            return curried.apply(this, args2);
        }
    }
}

function trippleAdd(a, b, c) {
    return a + b + c;
}

cTrippleAdd = curry(trippleAdd);

console.log(cTrippleAdd(1)(2)(3)); //6
console.log(cTrippleAdd(1, 2)(3)); //6
console.log(cTrippleAdd(1, 2, 3)); //6