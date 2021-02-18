#pragma once
#include <iostream>
#include "Product.h"
#include <vector>

using namespace std;


class Cart{
private:
	vector<Product*> products;
public:
	Cart();

	Cart(const vector<Product*>& _products);

	Cart(const Cart& other);

	Cart& operator=(const Cart& other);

	~Cart();

	void setProducts(const vector<Product*>& _products);
	vector<Product*> getProducts() const;

	double getPrice() const;
	void addProduct(Product* product);
	void deleteProduct(Product* product);
};