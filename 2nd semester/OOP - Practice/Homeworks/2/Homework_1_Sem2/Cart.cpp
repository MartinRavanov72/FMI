#include <iostream> 
#include "Cart.h"

using namespace std;


Cart::Cart(){
}

Cart::Cart(const Product* _products, int _productsNumber){
	this->setProductsNumber(_productsNumber);
	this->setProducts(_products);
}

Cart::Cart(const Cart& other){
	this->setProductsNumber(other.getProductsNumber());
	this->setProducts(other.getProducts());
}

Cart& Cart::operator=(const Cart& other){
	if(this == &other){
		return *this;
	}

	this->setProductsNumber(other.getProductsNumber());
	this->setProducts(other.getProducts());

	return *this;
}

Cart::~Cart(){
	delete[] this->products;
}

void Cart::setProducts(const Product* _products){
	delete[] this->products;
	int length = this->getProductsNumber();
	this->products = new Product[length];
	for(int i = 0; i < length; i++){
		this->products[i] = _products[i];
	}
}

Product* Cart::getProducts() const{
	return this->products;
}

void Cart::setProductsNumber(int _productsNumber){
	if(_productsNumber >= 0){
		this->productsNumber = _productsNumber;
	} else{
		cout << "Number of products cannot be < 0!" << endl;
	}
}

int Cart::getProductsNumber() const{
	return this->productsNumber;
}

double Cart::getPrice() const{
	double sum = 0;
	int length = this->getProductsNumber();
	for(int i = 0; i < length; i++){
		sum += this->getProducts()[i].getPrice();
	}
	return sum;
}

void Cart::addProduct(const Product& _product){
	if(this->products == nullptr){
		this->products = new Product[1];
		this->products[0] = _product;
		this->setProductsNumber(this->getProductsNumber() + 1);
	} else{
		int length = this->getProductsNumber();
		Product* productsNew = new Product[length + 1];
		for(int i = 0; i < length; i++){
			productsNew[i] = this->products[i];
		}
		delete[] this->products;
		this->products = new Product[length + 1];
		for(int i = 0; i < length; i++){
			this->products[i] = productsNew[i];
		}
		this->products[length] = _product;
		this->setProductsNumber(this->getProductsNumber() + 1);
		delete[] productsNew;
	}
}

void Cart::deleteProduct(const Product& _product){
	int length = this->getProductsNumber();
	if(length == 1){
		delete[] this->products;
		this->setProductsNumber(0);
		this->products = nullptr;
	} else{
		Product* productsNew = new Product[length - 1];
		int cnt = 0;
		for(int i = 0; i < length; i++){
			if(this->products[i] == _product){

			} else{
				productsNew[cnt] = this->products[i];
				cnt++;
			}
		}
		delete[] this->products;
		this->products = new Product[length - 1];
		for(int i = 0; i < length - 1; i++){
			this->products[i] = productsNew[i];
		}
		this->setProductsNumber(this->getProductsNumber() - 1);
		delete[] productsNew;
	}
}

