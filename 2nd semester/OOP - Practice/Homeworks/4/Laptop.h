#pragma once
#include <iostream> 
#include "Product.h" 
#include <string>

using namespace std;


class Laptop : public Product{
private:
	string make;
	int year = 0;
	double weight = 0;
public:
	Laptop();

	Laptop(int _id, double _price, const string& _name, const string& _shortDescription, const string& _longDescription, const string& _make, int _year, double _weight);

	Laptop(const Laptop& other);

	Laptop& operator=(const Laptop& other);

	~Laptop();

	void setMake(const string& _make);
	string getMake() const;
	void setYear(int _year);
	int getYear() const;
	void setWeight(double _weight);
	double getWeight() const;

	void printFullInfo() const override;
	void printShortInfo() const override;
};