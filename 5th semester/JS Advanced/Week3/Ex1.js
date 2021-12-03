function memoize(fn) {
    let dictObj = {};
    return function () {
        let key = Array.prototype.slice.call(arguments).join("-");

        if (!dictObj.hasOwnProperty(key)) {
            dictObj[key] = fn.apply(this, arguments);
        }
        
        return dictObj[key];
    }
}

var sum = function (x, y) { return x; }
var memSum = memoize(sum);
console.log(memSum({}, {})); // пресмята, връща 5
console.log(memSum({}, {aasd:'asd'})); // пресмята, връща 6
console.log(memSum(2,3)); // директно връща 5 без да смята