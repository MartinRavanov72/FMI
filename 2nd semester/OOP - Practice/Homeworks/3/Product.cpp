#include <iostream> 
#include "Product.h"

using namespace std;


Product::Product(){
	this->likes = 0;
	this->id = 0;
	this->price = 0;
}

Product::Product(int _id, double _price, const String& _name, const String& _shortDescription, const String& _longDescription){
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
	return this->getId() == other.getId();
}

Product::~Product(){
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

void Product::setName(const String& _name){
	this->name = _name;
}

String Product::getName() const{
	return this->name;
}

void Product::setShortDescription(const String& _shortDescription){
	this->shortDescription = _shortDescription;
}

String Product::getShortDescription() const{
	return this->shortDescription;
}

void Product::setLongDescription(const String& _longDescription){
	this->longDescription = _longDescription;
}

String Product::getLongDescription() const{
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