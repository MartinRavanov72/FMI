#pragma once
#include <iostream> 
#include "Product.h" 

using namespace std;


class PC: public Product{
private:
	String make;
	int year = 0;
	bool hasMonitor = false;
public:
	PC();

	PC(int _id, double _price, const String& _name, const String& _shortDescription, const String& _longDescription, const String& _make, int _year, bool _hasMonitor);

	PC(const PC& other);

	PC& operator=(const PC& other);

	~PC();

	void setMake(const String& _make);
	String getMake() const;
	void setYear(int _year);
	int getYear() const;
	void setHasMonitor(bool _hasMonitor);
	bool getHasMonitor() const;

	void printFullInfo() const override;
	void printShortInfo() const override;
};