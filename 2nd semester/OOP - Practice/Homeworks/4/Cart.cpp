#include "Cart.h"

using namespace std;


Cart::Cart(){
}

Cart::Cart(const vector<Product*>& _products){
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

void Cart::setProducts(const vector<Product*>& _products){
	this->products = _products;
}

vector<Product*> Cart::getProducts() const{
	return this->products;
}

double Cart::getPrice() const{
	double sum = 0;
	int length = this->getProducts().size();
	for(int i = 0; i < length; i++){
		sum += this->getProducts()[i]->getPrice();
	}
	return sum;
}

void Cart::addProduct(Product* product){
	int length = this->getProducts().size();
	bool hasSuchProduct = false;
	for(int i = 0; i < length; i++){
		if(*(this->getProducts()[i]) == *product){
			hasSuchProduct = true;
			break;
		}
	}
	if(!hasSuchProduct){
		this->products.push_back(product);
	} else{
		cout << "There already is such a product" << endl;
	}
}

void Cart::deleteProduct(Product* product){
	int length = this->getProducts().size();
	for(int i = 0; i < length; i++){
		if(*(this->getProducts()[i]) == *product){
			this->products.erase(this->products.begin() + i);
			return;
		}
	}
	cout << "No such product found" << endl;
}

