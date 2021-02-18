#pragma once
#include <iostream> 
#include "Product.h" 

using namespace std;


class Laptop : public Product{
private:
	String make;
	int year = 0;
	double weight = 0;
public:
	Laptop();

	Laptop(int _id, double _price, const String& _name, const String& _shortDescription, const String& _longDescription, const String& _make, int _year, double _weight);

	Laptop(const Laptop& other);

	Laptop& operator=(const Laptop& other);

	~Laptop();

	void setMake(const String& _make);
	String getMake() const;
	void setYear(int _year);
	int getYear() const;
	void setWeight(double _weight);
	double getWeight() const;

	void printFullInfo() const override;
	void printShortInfo() const override;
};