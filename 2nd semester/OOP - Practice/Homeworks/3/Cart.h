#pragma once
#include <iostream>
#include "Product.h"
#include "Vector.h"

using namespace std;


class Cart{
private:
	Vector<Product> products;
public:
	Cart();

	Cart(const Vector<Product>& _products);

	Cart(const Cart& other);

	Cart& operator=(const Cart& other);

	~Cart();

	void setProducts(const Vector<Product>& _products);
	Vector<Product> getProducts() const;

	double getPrice() const;
	void addProduct(const Product& product);
	void deleteProduct(const Product& product);
};