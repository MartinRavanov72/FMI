#pragma once
#include <iostream>
#include "Product.h"

using namespace std;


class Cart{
	private:
	Product* products = nullptr;
	int productsNumber = 0;
	public:
	Cart();

	Cart(const Product* _products, int _productsNumber);

	Cart(const Cart& other);

	Cart& operator=(const Cart& other);

	~Cart();

	void setProducts(const Product* _products);
	Product* getProducts() const;
	void setProductsNumber(int _productsNumber);
	int getProductsNumber() const;

	double getPrice() const;
	void addProduct(const Product& _product);
	void deleteProduct(const Product& _product);
};