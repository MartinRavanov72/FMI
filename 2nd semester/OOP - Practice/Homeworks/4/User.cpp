#include "User.h"
#include "Sale.h"

using namespace std;


User::User(){
	this->id = 0;
	this->money = 0;
	this->isTrustedUser = false;
	this->isLoggedIn = false;
}

User::User(int _id, double _money, const string& _password, const string& _name, const string& _description){
	this->setId(_id);
	this->setMoney(_money);
	this->setPassword(_password);
	this->setName(_name);
	this->setDescription(_description);
	this->setIsTrustedUser(false);
	this->logOut();
}

User::User(const User& other){
	this->setId(other.getId());
	this->setMoney(other.getMoney());
	this->setPassword(other.getPassword());
	this->setName(other.getName());
	this->setCart(other.getCart());
	this->setDescription(other.getDescription());
	this->setIsTrustedUser(other.getIsTrustedUser());
	this->setProductsBought(other.getProductsBought());
	this->setProductsForSale(other.getProductsForSale());
	if(other.getLoginStatus()){
		this->logIn();
	} else{
		this->logOut();
	}
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
	this->setProductsBought(other.getProductsBought());
	this->setProductsForSale(other.getProductsForSale());
	if(other.getLoginStatus()){
		this->logIn();
	} else{
		this->logOut();
	}

	return *this;
}

bool User::operator==(const User& other){
	return this->getId() == other.getId();
}

User::~User(){
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

void User::setName(const string& _name){
	this->name = _name;
}

string User::getName() const{
	return this->name;
}

void User::setPassword(const string& _password){
	this->password = _password;
}

string User::getPassword() const{
	return this->password;
}

void User::setCart(const Cart& _cart){
	this->cart = _cart;
}

Cart User::getCart() const{
	return this->cart;
}

void User::setProductsForSale(const vector<Product*>& _productsForSale){
	this->productsForSale = _productsForSale;
}

vector<Product*> User::getProductsForSale() const{
	return this->productsForSale;
}

void User::addProductForSale(Product* _productForSale){
	int length = this->getProductsForSale().size();
	bool hasSuchProduct = false;
	for(int i = 0; i < length; i++){
		if(*(this->getProductsForSale()[i]) == *_productForSale){
			hasSuchProduct = true;
			break;
		}
	}
	if(!hasSuchProduct){
		this->productsForSale.push_back(_productForSale);
	} else{
		cout << "There already is such a product" << endl;
	}
}

void User::deleteProductForSale(Product* _productForSale){
	int length = this->getProductsForSale().size();
	for(int i = 0; i < length; i++){
		if(*(this->getProductsForSale()[i]) == *_productForSale){
			this->productsForSale.erase(this->productsForSale.begin() + i);
			return;
		}
	}
	cout << "No such product found" << endl;
}

void User::setProductsBought(const vector<Product*>& _productsBought){
	this->productsBought = _productsBought;
}

vector<Product*> User::getProductsBought() const{
	return this->productsBought;
}

void User::addProductBought(Product* _productBought){
	int length = this->getProductsBought().size();
	bool hasSuchProduct = false;
	for(int i = 0; i < length; i++){
		if(*(this->getProductsBought()[i]) == *_productBought){
			hasSuchProduct = true;
			break;
		}
	}
	if(!hasSuchProduct){
		this->productsBought.push_back(_productBought);
	} else{
		cout << "There already is such a product" << endl;
	}
}

void User::setDescription(const string& _description){
	this->description = _description;
}

string User::getDescription() const{
	return this->description;
}

void User::setIsTrustedUser(bool _value){
	this->isTrustedUser = _value;
}

bool User::getIsTrustedUser() const{
	return this->isTrustedUser;
}

void User::logIn(){
	this->isLoggedIn = true;
}

void User::logOut(){
	this->isLoggedIn = false;
}

bool User::getLoginStatus() const{
	return this->isLoggedIn;
}

void User::printFullInfo() const{
	cout << "User " << this->getName() << " with Id " << this->getId() << ", has " << this->getMoney() << "$ and the products he/she has for sale are: ";
	int length = this->getProductsForSale().size();
	for(int i = 0; i < length; i++){
		cout << this->getProductsForSale()[i]->getName() << " ";
	}

	cout << "." << endl << "He/She has already bought: ";

	length = this->getProductsBought().size();
	for(int i = 0; i < length; i++){
		cout << this->getProductsBought()[i]->getName() << " ";
	}

	cout << "." << endl << "Here is some info about him/her: " << this->getDescription();
	if(this->getIsTrustedUser()){
		cout << "He/She is a trusted user!";
	}

	cout << endl;
}

void User::addLike(Product* _product){
	if(this->getLoginStatus()){
		_product->addLike();
	}
}

void User::addProductToCart(Product* _product, const User& _seller){
	int length = _seller.getProductsForSale().size();
	bool isForSale = false;
	for(int i = 0; i < length; i++){
		if(*_product == *(_seller.getProductsForSale()[i])){
			isForSale = true;
			break;
		}
	}
	if(isForSale){
		this->cart.addProduct(_product);
	} else{
		cout << "The product " << _product->getName() << " is not for sale :(" << endl;
	}
}

void User::buyProductsFromCart(User& _seller){
	int lengthOfCart = this->getCart().getProducts().size();
	int lengthOfSellerProductsForSale = _seller.getProductsForSale().size();
	if(lengthOfCart == 0){
		cout << "There are no products in the cart." << endl;
		return;
	}
	for(int i = 0; i < lengthOfCart; i++){
		for(int j = 0; j < lengthOfSellerProductsForSale; j++){
			if(lengthOfCart == 0){
				break;
			}
			if(*(_seller.getProductsForSale()[j]) == *(this->getCart().getProducts()[i])){
				Sale sale(this->getCart().getProducts()[i]->getPrice(), this->getCart().getProducts()[i], this, &_seller);
				bool isCompleted = sale.start();
				if(isCompleted){
					this->addProductBought(this->getCart().getProducts()[i]);
					_seller.deleteProductForSale(this->getCart().getProducts()[i]);
					this->cart.deleteProduct(this->getCart().getProducts()[i]);

					j--;
					lengthOfSellerProductsForSale--;
					lengthOfCart--;
				}
			}
		}
	}
}