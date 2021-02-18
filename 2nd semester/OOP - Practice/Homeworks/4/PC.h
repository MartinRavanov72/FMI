#pragma once
#include <iostream> 
#include <string>
#include "Product.h" 

using namespace std;


class PC: public Product{
private:
    string make;
	int year = 0;
	bool hasMonitor = false;
public:
	PC();

	PC(int _id, double _price, const string& _name, const string& _shortDescription, const string& _longDescription, const string& _make, int _year, bool _hasMonitor);

	PC(const PC& other);

	PC& operator=(const PC& other);

	~PC();

	void setMake(const string& _make);
	string getMake() const;
	void setYear(int _year);
	int getYear() const;
	void setHasMonitor(bool _hasMonitor);
	bool getHasMonitor() const;

	void printFullInfo() const override;
	void printShortInfo() const override;
};