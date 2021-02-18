#include "Phone.h"

Phone::Phone(): Product(){
	this->cameraMegapixel = 0;
	this->isTouchscreen = false;
}

Phone::Phone(int _id, double _price, const string& _name, const string& _shortDescription, const string& _longDescription, const string& _make, double _cameraMegapixel, bool _isTouchscreen) : Product(_id, _price, _name, _shortDescription, _longDescription){
	this->setMake(_make);
	this->setCameraMegapixel(_cameraMegapixel);
	this->setIsTouchscreen(_isTouchscreen);
}

Phone::Phone(const Phone& other): Product(other){
	this->setMake(other.getMake());
	this->setCameraMegapixel(other.getCameraMegapixel());
	this->setIsTouchscreen(other.getIsTouchscreen());
}

Phone& Phone::operator=(const Phone& other){
	if(this == &other){
		return *this;
	}

	Product::operator =(other);

	this->setMake(other.getMake());
	this->setCameraMegapixel(other.getCameraMegapixel());
	this->setIsTouchscreen(other.getIsTouchscreen());

	return *this;
}

Phone::~Phone(){}

void Phone::setMake(const string& _make){
	this->make = _make;
}

string Phone::getMake() const{
	return this->make;
}

void Phone::setCameraMegapixel(double _cameraMegapixel){
	if(_cameraMegapixel >= 0){
		this->cameraMegapixel = _cameraMegapixel;
	} else{
		cout << "Camera megapixels cannot be < 0!" << endl;
	}
}

double Phone::getCameraMegapixel() const{
	return this->cameraMegapixel;
}

void Phone::setIsTouchscreen(bool _isTouchscreen){
	this->isTouchscreen = _isTouchscreen;
}

bool Phone::getIsTouchscreen() const{
	return this->isTouchscreen;
}

void Phone::printFullInfo() const{
	cout << "This Phone " << this->getName() << " with Id: " << this->getId() << ", is worth " << this->getPrice() << "$ and its make is " << this->getMake() << ", and it has a " << this->getCameraMegapixel() << " megapixel camera, it " << (this->getIsTouchscreen() ? "is" : "isn't") << " touchscreen. Here you can learn more about the product: " << this->getLongDescription() << "It has been liked " << this->getLikes() << " times." << endl;
}

void Phone::printShortInfo() const{
	cout << "This Phone " << this->getName() << ", " << this->getMake() << " is worth " << this->getPrice() << "$. Here you can learn something about the product: " << this->getShortDescription() << endl;
}
