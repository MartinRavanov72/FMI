#include <iostream> 
#include "Sale.h"

using namespace std;


Sale::Sale(){
	this->giver = nullptr;
	this->receiver = nullptr;
	this->amount = 0;
}

Sale::Sale(double _amount, const Product& _product, User* _giver, User* _receiver){
	this->setAmount(_amount);
	this->setProduct(_product);
	this->setGiver(_giver);
	this->setReceiver(_receiver);
}

Sale::Sale(const Sale& other){
	this->setAmount(other.getAmount());
	this->setGiver(other.getGiver());
	this->setProduct(other.getProduct());
	this->setReceiver(other.getReceiver());
}

Sale& Sale::operator=(const Sale& other){
	if(this == &other){
		return *this;
	}

	this->setAmount(other.getAmount());
	this->setGiver(other.getGiver());
	this->setProduct(other.getProduct());
	this->setReceiver(other.getReceiver());

	return *this;
}

Sale::~Sale(){

}

void Sale::setAmount(double _amount){
	if(_amount >= 0){
		this->amount = _amount;
	} else{
		cout << "Amount cannot be < 0!" << endl;
	}
}

double Sale::getAmount() const{
	return this->amount;
}

void Sale::setProduct(const Product& _product){
	this->product = _product;
}

Product Sale::getProduct() const{
	return this->product;
}

void Sale::setGiver(User* _giver){
	this->giver = _giver;
}

User* Sale::getGiver() const{
	return this->giver;
}

void Sale::setReceiver(User* _receiver){
	this->receiver = _receiver;
}

User* Sale::getReceiver() const{
	return this->receiver;
}

bool Sale::start(){
	if(this->getGiver()->getMoney() < this->getAmount() || !this->getGiver()->getLoginStatus() || !this->getReceiver()->getLoginStatus()){
		cout << "The payment for " << this->getProduct().getName() << " for " << this->getAmount() << "$ failed" << endl;
		return false;
	} else{
		this->giver->setMoney(this->getGiver()->getMoney() - this->getAmount());
		this->receiver->setMoney(this->getReceiver()->getMoney() + this->getAmount());
		this->receiver->addProductBought(this->getProduct());
		cout << "The payment for " << this->getProduct().getName() << " for " << this->getAmount() << "$ is successful" << endl;
		return true;
	}
	
}