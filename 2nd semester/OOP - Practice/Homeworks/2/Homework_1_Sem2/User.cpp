#include <iostream> 
#include <cstring>
#include "User.h"
#include "Sale.h"

using namespace std;


User::User(){
}

User::User(int _id, double _money, const char* _password, const char* _name, const char* _description){
	this->setId(_id);
	this->setMoney(_money);
	this->setPassword(_password);
	this->setName(_name);
	this->setDescription(_description);
	this->setIsTrustedUser(false);
}

User::User(const User& other){
	this->setId(other.getId());
	this->setMoney(other.getMoney());
	this->setPassword(other.getPassword());
	this->setName(other.getName());
	this->setCart(other.getCart());
	this->setDescription(other.getDescription());
	this->setIsTrustedUser(other.getIsTrustedUser());
	this->setProductsBoughtNumber(other.getProductsBoughtNumber());
	this->setProductsBought(other.getProductsBought(), other.getProductsBoughtNumber());
	this->setProductsForSaleNumber(other.getProductsForSaleNumber());
	this->setProductsForSale(other.getProductsForSale(), other.getProductsForSaleNumber());
}

User& User::operator=(const User& other){
	if(this == &other){
		return *this;
	}

	this->setId(other.getId());
	this->setMoney(other.getMoney());
	this->setPassword(other.getPassword());
	this->setName(other.getName());
	this->setCart(other.getCart());
	this->setDescription(other.getDescription());
	this->setIsTrustedUser(other.getIsTrustedUser());
	this->setProductsBoughtNumber(other.getProductsBoughtNumber());
	this->setProductsBought(other.getProductsBought(), other.getProductsBoughtNumber());
	this->setProductsForSaleNumber(other.getProductsForSaleNumber());
	this->setProductsForSale(other.getProductsForSale(), other.getProductsForSaleNumber());

	return *this;
}

User::~User(){
	delete[] this->name;
	delete[] this->password;
	delete[] this->description;
	delete[] this->productsBought;
	delete[] this->productsForSale;
}


void User::setId(int _id){
	if(_id >= 0){
		this->id = _id;
	} else{
		cout << "Id cannot be < 0!" << endl;
	}
}

int User::getId() const{
	return this->id;
}

void User::setMoney(double _money){
	if(_money >= 0){
		this->money = _money;
	} else{
		cout << "Money cannot be < 0!" << endl;
	}
}

double User::getMoney() const{
	return this->money;
}

void User::setName(const char* _name){
	delete[] this->name;
	this->name = new char[strlen(_name) + 1];
	strcpy_s(this->name, strlen(_name) + 1, _name);
}

const char* User::getName() const{
	return this->name;
}

void User::setPassword(const char* _password){
	delete[] this->password;
	this->password = new char[strlen(_password) + 1];
	strcpy_s(this->password, strlen(_password) + 1, _password);
}

const char* User::getPassword() const{
	return this->password;
}

void User::setCart(const Cart& _cart){
	this->cart = _cart;
}

Cart User::getCart() const{
	return this->cart;
}

void User::setProductsForSale(const Product* _productsForSale, int _length){
	if(_length < 0){
		cout << "Length cannot be < 0!" << endl;
	} else{
		delete[] this->productsForSale;
		this->productsForSale = new Product[_length];
		for(int i = 0; i < _length; i++){
			this->productsForSale[i] = _productsForSale[i];
		}
	}
}

Product* User::getProductsForSale() const{
	return this->productsForSale;
}

void User::addProductForSale(const Product& _productForSale){
	if(this->productsForSale == nullptr){
		this->productsForSale = new Product[1];
		this->productsForSale[0] = _productForSale;
		this->setProductsForSaleNumber(this->getProductsForSaleNumber() + 1);
	} else{
		int length = this->getProductsForSaleNumber();
		Product* productsForSaleNew = new Product[length+1];
		for(int i = 0; i < length; i++){
			productsForSaleNew[i] = this->productsForSale[i];
		}
		delete[] this->productsForSale;
		this->productsForSale = new Product[length + 1];
		for(int i = 0; i < length; i++){
			this->productsForSale[i] = productsForSaleNew[i];
		}
		this->productsForSale[length] = _productForSale;
		this->setProductsForSaleNumber(this->getProductsForSaleNumber() + 1);
		delete[] productsForSaleNew;
	}
}

void User::deleteProductForSale(const Product& _productForSale){
	int length = this->getProductsForSaleNumber();
	if(length == 1){
		delete[] this->productsForSale;
		this->setProductsForSaleNumber(0);
		this->productsForSale = nullptr;
	} else{
		Product* productsForSaleNew = new Product[length - 1];
		int cnt = 0;
		for(int i = 0; i < length; i++){
			if(this->productsForSale[i] == _productForSale){

			} else{
				productsForSaleNew[cnt] = this->productsForSale[i];
				cnt++;
			}
		}
		delete[] this->productsForSale;
		this->productsForSale = new Product[length - 1];
		for(int i = 0; i < length - 1; i++){
			this->productsForSale[i] = productsForSaleNew[i];
		}
		this->setProductsForSaleNumber(this->getProductsForSaleNumber() - 1);
		delete[] productsForSaleNew;
	}
}

void User::setProductsForSaleNumber(int _productsForSaleNumber){
	if(_productsForSaleNumber >= 0){
		this->productsForSaleNumber = _productsForSaleNumber;
	} else{
		cout << "Number of products cannot be < 0!" << endl;
	}
}

int User::getProductsForSaleNumber() const{
	return this->productsForSaleNumber;
}

void User::setProductsBought(const Product* _productsBought, int _length){
	if(_length < 0){
		cout << "Length cannot be < 0!" << endl;
	} else{
		delete[] this->productsBought;
		this->productsBought = new Product[_length];
		for(int i = 0; i < _length; i++){
			this->productsBought[i] = _productsBought[i];
		}
	}
}

Product* User::getProductsBought() const{
	return this->productsBought;
}

void User::addProductBought(const Product& _productBought){
	if(this->productsBought == nullptr){
		this->productsBought = new Product[1];
		this->productsBought[0] = _productBought;
		this->setProductsBoughtNumber(this->getProductsBoughtNumber() + 1);
	} else{
		int length = this->getProductsBoughtNumber();
		Product* productsBoughtNew = new Product[length + 1];
		for(int i = 0; i < length; i++){
			productsBoughtNew[i] = this->productsBought[i];
		}
		delete[] this->productsBought;
		this->productsBought = new Product[length + 1];
		for(int i = 0; i < length; i++){
			this->productsBought[i] = productsBoughtNew[i];
		}
		this->productsBought[length] = _productBought;
		this->setProductsBoughtNumber(this->getProductsBoughtNumber() + 1);
		delete[] productsBoughtNew;
	}
}

void User::setProductsBoughtNumber(int _productsBoughtNumber){
	if(_productsBoughtNumber >= 0){
		this->productsBoughtNumber = _productsBoughtNumber;
	} else{
		cout << "Number of products cannot be < 0!" << endl;
	}
}

int User::getProductsBoughtNumber() const{
	return this->productsBoughtNumber;
}

void User::setDescription(const char* _description){
	delete[] this->description;
	this->description = new char[strlen(_description) + 1];
	strcpy_s(this->description, strlen(_description) + 1, _description);
}

const char* User::getDescription() const{
	return this->description;
}

void User::setIsTrustedUser(bool _value){
	this->isTrustedUser = _value;
}

bool User::getIsTrustedUser() const{
	return this->isTrustedUser;
}

void User::printFullInfo() const{
	cout << "User " << this->getName() << " with Id " << this->getId() << ", has " << this->getMoney() << "$ and the products he has for sale are: " << this->getProductsForSale() << ". He/She has already bought: " << this->getProductsBought() << ". Here is some info about him/her: " << this->getDescription();
	if(this->getIsTrustedUser()){
		cout << "He/She is a trusted user!";
	}

	cout << endl;
}

void User::addLike(Product& _product){
	_product.addLike();
}

void User::addProductToCart(Product& _product, const User& _seller){
	int length = _seller.getProductsForSaleNumber();
	bool isForSale = false;
	for(int i = 0; i < length; i++){
		if(_product == _seller.getProductsForSale()[i]){
			isForSale = true;
			break;
		}
	}
	if(isForSale){
		this->cart.addProduct(_product);
	} else{
		cout << "The product " << _product.getName() << " is not for sale :(" << endl;
	}
}

void User::buyProductsFromCart(User& _seller){
	int lengthOfCart = this->getCart().getProductsNumber();
	int lengthOfSellerProductsForSale = _seller.getProductsForSaleNumber();
	if(lengthOfCart == 0){
		cout << "There are no products in the cart." << endl;
	} else{
		int salesNumber = 0;
		for(int i = 0; i < lengthOfCart; i++){
			for(int j = 0; j < lengthOfSellerProductsForSale; j++){
				if(salesNumber == lengthOfSellerProductsForSale){  //all the sales are done
					i = lengthOfCart;
					break;
				}
				if(_seller.getProductsForSale()[j] == this->getCart().getProducts()[i]){
					Sale sale(this->getCart().getProducts()[i].getPrice(), this->getCart().getProducts()[i], this, &_seller);
					bool isCompleted = sale.start();
					if(isCompleted){
						this->addProductBought(this->getCart().getProducts()[i]);
						_seller.deleteProductForSale(this->getCart().getProducts()[i]);
						this->cart.deleteProduct(this->getCart().getProducts()[i]);

						lengthOfCart--;
						i--;
						salesNumber++;
					}
				}
			}
		}
	}
}