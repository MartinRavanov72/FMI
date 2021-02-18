#include <iostream> 
#include "Cart.h"

using namespace std;


Cart::Cart(){
}

Cart::Cart(const Vector<Product>& _products){
	this->setProducts(_products);
}

Cart::Cart(const Cart& other){
	this->setProducts(other.getProducts());
}

Cart& Cart::operator=(const Cart& other){
	if(this == &other){
		return *this;
	}

	this->setProducts(other.getProducts());

	return *this;
}

Cart::~Cart(){
}

void Cart::setProducts(const Vector<Product>& _products){
	this->products = _products;
}

Vector<Product> Cart::getProducts() const{
	return this->products;
}

double Cart::getPrice() const{
	double sum = 0;
	int length = this->getProducts().getSize();
	for(int i = 0; i < length; i++){
		sum += this->getProducts()[i].getPrice();
	}
	return sum;
}

void Cart::addProduct(const Product& product){
	int length = this->getProducts().getSize();
	bool hasSuchProduct = false;
	for(int i = 0; i < length; i++){
		if(this->getProducts()[i] == product){
			hasSuchProduct = true;
			break;
		}
	}
	if(!hasSuchProduct){
		this->products.pushBack(product);
	} else{
		cout << "No such product found" << endl;
	}
}

void Cart::deleteProduct(const Product& product){
	int length = this->getProducts().getSize();
	for(int i = 0; i < length; i++){
		if(this->getProducts()[i] == product){
			this->products.removeAt(i);
			return;
		}
	}
	cout << "No such product found" << endl;
}

