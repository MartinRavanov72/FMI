#pragma once
#include <iostream>
#include "Cart.h"
#include "Product.h"
#include "String.h"
#include "Vector.h"

using namespace std;


class User{
private:
	int id = 0;
	double money = 0;
	String name;
	String password;
	Cart cart;
	Vector<Product> productsForSale;
	Vector<Product> productsBought;
	String description;
	bool isTrustedUser = false;
	bool isLoggedIn = false;

	void setId(int _id);
	void setPassword(const String& _password);
	void setName(const String& _name);
public:
	User();

	User(int _id, double _money, const String& _password, const String& _name, const String& _description);

	User(const User& other);

	User& operator=(const User& other);

	bool operator==(const User& other);

	~User();


	int getId() const;
	void setMoney(double _money);
	double getMoney() const;
	String getName() const;
	String getPassword() const;
	void setCart(const Cart& _cart);
	Cart getCart() const;
	void setProductsForSale(const Vector<Product>& _productsForSale);
	Vector<Product> getProductsForSale() const;
	void setProductsBought(const Vector<Product>& _productsBought);
	Vector<Product> getProductsBought() const;
	void setDescription(const String& _description);
	String getDescription() const;
	void setIsTrustedUser(bool _value);
	bool getIsTrustedUser() const;
	void logIn();
	void logOut();
	bool getLoginStatus() const;

	void addProductForSale(const Product& _productForSale);
	void deleteProductForSale(const Product& _productForSale);
	void addProductBought(const Product& _productBought);
	void printFullInfo() const;
	void addLike(Product& _product);
	void addProductToCart(Product& _product, const User& _seller);
	void buyProductsFromCart(User& _seller);
};