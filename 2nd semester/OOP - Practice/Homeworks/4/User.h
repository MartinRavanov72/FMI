#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Cart.h"
#include "Product.h"

using namespace std;


class User{
private:
	int id = 0;
	double money = 0;
	string name;
	string password;
	Cart cart;
	vector<Product*> productsForSale;
	vector<Product*> productsBought;
	string description;
	bool isTrustedUser = false;
	bool isLoggedIn = false;

	void setId(int _id);
	void setPassword(const string& _password);
	void setName(const string& _name);
public:
	User();

	User(int _id, double _money, const string& _password, const string& _name, const string& _description);

	User(const User& other);

	User& operator=(const User& other);

	bool operator==(const User& other);

	~User();


	int getId() const;
	void setMoney(double _money);
	double getMoney() const;
	string getName() const;
	string getPassword() const;
	void setCart(const Cart& _cart);
	Cart getCart() const;
	void setProductsForSale(const vector<Product*>& _productsForSale);
	vector<Product*> getProductsForSale() const;
	void setProductsBought(const vector<Product*>& _productsBought);
	vector<Product*> getProductsBought() const;
	void setDescription(const string& _description);
	string getDescription() const;
	void setIsTrustedUser(bool _value);
	bool getIsTrustedUser() const;
	void logIn();
	void logOut();
	bool getLoginStatus() const;

	void addProductForSale(Product* _productForSale);
	void deleteProductForSale(Product* _productForSale);
	void addProductBought(Product* _productBought);
	void printFullInfo() const;
	void addLike(Product* _product);
	void addProductToCart(Product* _product, const User& _seller);
	void buyProductsFromCart(User& _seller);
};