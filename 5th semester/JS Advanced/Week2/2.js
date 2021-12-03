// var Person = function Person(name, age) {
//     this.name = name;
//     this.age = age;
// }

// var Student = function Student(name, age, grade) {
//     Person.call(this, name, age);
//     this.grade = grade;
// }

// Student.prototype = Person;

// var pesho = new Student('pesho', 21, 5.5);





function Point(x, y) {
    this.x = x;
    this.y = y;
}

Point.prototype.getDistance = function (point2) {
    return Math.sqrt(Math.pow(this.x - point2.x, 2) + Math.pow(this.y - point2.y, 2));
}

var point1 = new Point(3, 4);
var point2 = new Point(5, 6);

console.log(point1.getDistance(point2));







function Circle(x, y, r) {
    this.point = new Point(x, y);
    this.r = r;
}

Circle.prototype.getCircumference = function () {
    return this.r * 2 * Math.PI;
}

Circle.prototype.getArea = function () {
    return Math.PI * this.r * this.r;
}

Circle.prototype.intersects = function (circle2) {
    if (Math.abs(this.r - circle2.r) < this.point.getDistance(circle2.point) && this.point.getDistance(circle2.point) < this.r + circle2.r) {
        return true;
    };

    return false;
}

var circle1 = new Circle(3, 4, 1.01);
var circle2 = new Circle(5, 4, 1);

console.log(circle1.intersects(circle2));







function Rectangle(x, y, a, b) {
    Point.call(this, x, y);
    this.a = a;
    this.b = b;
}

Rectangle.prototype = Object.create(Point.prototype);

Rectangle.prototype.getPerimeter = function () {
    return 2*(this.a + this.b);
}

Rectangle.prototype.getArea = function () {
    return this.a * this.b;
}

Rectangle.prototype.getLengthOfDiagonals = function () {
    return [Math.sqrt(this.a * this.a + this.b * this.b), Math.sqrt(this.a * this.a + this.b * this.b)];
}

Rectangle.prototype.getBiggestCircle = function () {
    return new Circle((this.x + this.x + this.a) / 2, (this.y + this.y + this.b) / 2, +this.getLengthOfDiagonals()[0] / 2);
}

var rect1 = new Rectangle(1, 1, 4, 3);
console.log(rect1.getLengthOfDiagonals());
console.log(rect1.getBiggestCircle());






function RectanglePrism(x, y, a, b, c) {
    Rectangle.call(this, x, y, a, b);
    this.c = c;
}

RectanglePrism.prototype = Object.create(Rectangle.prototype);

RectanglePrism.prototype.getVolume = function () {
    return this.getArea() * this.c;
}

var rectPrism = new RectanglePrism(2, 2, 4, 3, 5);
console.log(rectPrism.getVolume());