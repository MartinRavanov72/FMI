#pragma once
#include <iostream> 
#include "User.h"
#include "Product.h"

using namespace std;


class Sale{
private:
	double amount = 0;
	Product product;
	User* giver = nullptr;
	User* receiver = nullptr;

	void setAmount(double _amount);
public:
	Sale();

	Sale(double _amount, const Product& _product, User* _giver, User* _receiver);

	Sale(const Sale& other);

	Sale& operator=(const Sale& other);

	~Sale();


	double getAmount() const;
	void setProduct(const Product& _giver);
	Product getProduct() const;
	void setGiver(User* _giver);
	User* getGiver() const;
	void setReceiver(User* _receiver);
	User* getReceiver() const;

	bool start();
};