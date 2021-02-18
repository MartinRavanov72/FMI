#include "Laptop.h"

Laptop::Laptop() : Product(){
	this->year = 0;
	this->weight = 0;
}

Laptop::Laptop(int _id, double _price, const string& _name, const string& _shortDescription, const string& _longDescription, const string& _make, int _year, double _weight) : Product(_id, _price, _name, _shortDescription, _longDescription){
	this->setMake(_make);
	this->setYear(_year);
	this->setWeight(_weight);
}

Laptop::Laptop(const Laptop& other) : Product(other){
	this->setMake(other.getMake());
	this->setYear(other.getYear());
	this->setWeight(other.getWeight());
}

Laptop& Laptop::operator=(const Laptop & other){
	if(this == &other){
		return *this;
	}

	Product::operator =(other);

	this->setMake(other.getMake());
	this->setYear(other.getYear());
	this->setWeight(other.getWeight());

	return *this;
}

Laptop::~Laptop(){}

void Laptop::setMake(const string& _make){
	this->make = _make;
}

string Laptop::getMake() const{
	return this->make;
}

void Laptop::setYear(int _year){
	if(_year >= 0){
		this->year = _year;
	} else{
		cout << "Year cannot be < 0!" << endl;
	}
}

int Laptop::getYear() const{
	return this->year;
}

void Laptop::setWeight(double _weight){
	if(_weight >= 0){
		this->weight = _weight;
	} else{
		cout << "Weight cannot be < 0!" << endl;
	}
}

double Laptop::getWeight() const{
	return this->weight;
}

void Laptop::printFullInfo() const{
	cout << "This laptop " << this->getName() << " with Id: " << this->getId() << ", is worth " << this->getPrice() << "$ and its make is " << this->getMake() << ", made in " << this->getYear() << " and it weighs " << this->getWeight() << "kg. Here you can learn more about the product: " << this->getLongDescription() << "It has been liked " << this->getLikes() << " times." << endl;
}

void Laptop::printShortInfo() const{
	cout << "This laptop " << this->getName() << ", " << this->getMake() << " is worth " << this->getPrice() << "$. Here you can learn something about the product: " << this->getShortDescription() << endl;
}
