#pragma once
#include <iostream>
#include "Cart.h"
#include "Product.h"

using namespace std;


class User{
	private:
	int id;
	double money;
	char* name = nullptr;
	char* password = nullptr;
	Cart cart;
	Product* productsForSale = nullptr;
	int productsForSaleNumber = 0;
	Product* productsBought = nullptr;
	int productsBoughtNumber = 0;
	char* description = nullptr;
	bool isTrustedUser;
	public:
	User();

	User(int _id, double _money, const char* _password, const char* _name, const char* _description);

	User(const User& other);

	User& operator=(const User& other);

	~User();

	void setId(int _id);
	int getId() const;
	void setMoney(double _money);
	double getMoney() const;
	void setName(const char* _name);
	const char* getName() const;
	void setPassword(const char* _password);
	const char* getPassword() const;
	void setCart(const Cart& _cart);
	Cart getCart() const;
	void setProductsForSale(const Product* _productsForSale, int _length);
	Product* getProductsForSale() const;
	void setProductsForSaleNumber(int _productsForSaleNumber);
	int getProductsForSaleNumber() const;
	void setProductsBought(const Product* _productsBought, int _length);
	Product* getProductsBought() const;
	void setProductsBoughtNumber(int _productsBoughtNumber);
	int getProductsBoughtNumber() const;
	void setDescription(const char* _description);
	const char* getDescription() const;
	void setIsTrustedUser(bool _value);
	bool getIsTrustedUser() const;

	void addProductForSale(const Product& _productForSale);
	void deleteProductForSale(const Product& _productForSale);
	void addProductBought(const Product& _productBought);
	void printFullInfo() const;
	void addLike(Product& _product);
	void addProductToCart(Product& _product, const User& _seller);
	void buyProductsFromCart(User& _seller);
};