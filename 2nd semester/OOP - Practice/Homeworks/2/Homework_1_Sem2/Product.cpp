#include <iostream> 
#include <cstring>
#include "Product.h"

using namespace std;


Product::Product(){
}

Product::Product(int _id, double _price, const char* _name, const char* _shortDescription, const char* _longDescription){
	this->setId(_id);
	this->setPrice(_price);
	this->setName(_name);
	this->setShortDescription(_shortDescription);
	this->setLongDescription(_longDescription);
}

Product::Product(const Product& other){
	this->setId(other.getId());
	this->setPrice(other.getPrice());
	this->setName(other.getName());
	this->setShortDescription(other.getShortDescription());
	this->setLongDescription(other.getLongDescription());
	this->setLikes(other.getLikes());
}

Product& Product::operator=(const Product& other){
	if(this == &other){
		return *this;
	}

	this->setId(other.getId());
	this->setPrice(other.getPrice());
	this->setName(other.getName());
	this->setShortDescription(other.getShortDescription());
	this->setLongDescription(other.getLongDescription());
	this->setLikes(other.getLikes());

	return *this;
}

bool Product::operator==(const Product& other){
	if(this->getId() == other.getId()){
		return true;
	}
	return false;
}

Product::~Product(){
	delete[] this->name;
	delete[] this->shortDescription;
	delete[] this->longDescription;
}

void Product::setId(int _id){
	if(_id >= 0){
		this->id = _id;
	} else{
		cout << "Id cannot be < 0!" << endl;
	}
}

int Product::getId() const{
	return this->id;
}

void Product::setPrice(double _price){
	if(_price >= 0){
		this->price = _price;
	} else{
		cout << "Price cannot be < 0!" << endl;
	}
}

double Product::getPrice() const{
	return this->price;
}

void Product::setName(const char* _name){
	delete[] this->name;
	this->name = new char[strlen(_name) + 1];
	strcpy_s(this->name, strlen(_name) + 1, _name);
}

const char* Product::getName() const{
	return this->name;
}

void Product::setShortDescription(const char* _shortDescription){
	delete[] this->shortDescription;
	this->shortDescription = new char[strlen(_shortDescription) + 1];
	strcpy_s(this->shortDescription, strlen(_shortDescription) + 1, _shortDescription);
}

const char* Product::getShortDescription() const{
	return this->shortDescription;
}

void Product::setLongDescription(const char* _longDescription){
	delete[] this->longDescription;
	this->longDescription = new char[strlen(_longDescription) + 1];
	strcpy_s(this->longDescription, strlen(_longDescription) + 1, _longDescription);
}

const char* Product::getLongDescription() const{
	return this->longDescription;
}

void Product::setLikes(int _likes){
	if(_likes >= 0){
		this->likes = _likes;
	} else{
		cout << "Number of likes cannot be < 0!" << endl;
	}
}

int Product::getLikes() const{
	return this->likes;
}

void Product::printFullInfo() const{
	cout << this->getName() << " with Id: " << this->getId() << ", is worth " << this->getPrice() << "$. Here you can learn more about the product: " << this->getLongDescription() << "It has been liked " << this->getLikes() << " times." << endl;
}

void Product::printShortInfo() const{
	cout << this->getName() << " is worth " << this->getPrice() << "$. Here you can learn something about the product: " << this->getShortDescription() << endl;
}

void Product::addLike(){
	this->setLikes(this->getLikes() + 1);
}