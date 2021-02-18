#include "PC.h"

PC::PC(): Product(){
	this->year = 0;
	this->hasMonitor = false;
}

PC::PC(int _id, double _price, const string& _name, const string& _shortDescription, const string& _longDescription, const string& _make, int _year, bool _hasMonitor) : Product(_id, _price, _name, _shortDescription, _longDescription){
	this->setMake(_make);
	this->setYear(_year);
	this->setHasMonitor(_hasMonitor);
}

PC::PC(const PC& other): Product(other){
	this->setMake(other.getMake());
	this->setYear(other.getYear());
	this->setHasMonitor(other.getHasMonitor());
}

PC& PC::operator=(const PC& other){
	if(this == &other){
		return *this;
	}

	Product::operator =(other);

	this->setMake(other.getMake());
	this->setYear(other.getYear());
	this->setHasMonitor(other.getHasMonitor());

	return *this;
}

PC::~PC(){}

void PC::setMake(const string& _make){
	this->make = _make;
}

string PC::getMake() const{
	return this->make;
}

void PC::setYear(int _year){
	if(_year >= 0){
		this->year = _year;
	} else{
		cout << "Year cannot be < 0!" << endl;
	}
}

int PC::getYear() const{
	return this->year;
}

void PC::setHasMonitor(bool _hasMonitor){
	this->hasMonitor = _hasMonitor;
}

bool PC::getHasMonitor() const{
	return this->hasMonitor;
}

void PC::printFullInfo() const{
	cout << "This PC " << this->getName() << " with Id: " << this->getId() << ", is worth " << this->getPrice() << "$ and its make is " << this->getMake() << ", made in " << this->getYear() << " and it " << (this->getHasMonitor() ? "has" : "doesn't have") << " a monitor. Here you can learn more about the product: " << this->getLongDescription() << "It has been liked " << this->getLikes() << " times." << endl;
}

void PC::printShortInfo() const{
	cout << "This PC " << this->getName() << ", " << this->getMake() << " is worth " << this->getPrice() << "$. Here you can learn something about the product: " << this->getShortDescription() << endl;
}
