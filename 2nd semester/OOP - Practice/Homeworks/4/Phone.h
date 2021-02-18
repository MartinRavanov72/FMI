#pragma once
#include <iostream> 
#include <string>
#include "Product.h" 

using namespace std;


class Phone: public Product{
private:
    string make;
	double cameraMegapixel = 0;
	bool isTouchscreen = false;
public:
	Phone();

	Phone(int _id, double _price, const string& _name, const string& _shortDescription, const string& _longDescription, const string& _make, double _cameraMegapixel, bool _isTouchscreen);

	Phone(const Phone& other);

	Phone& operator=(const Phone& other);

	~Phone();

	void setMake(const string& _make);
	string getMake() const;
	void setCameraMegapixel(double _cameraMegapixel);
	double getCameraMegapixel() const;
	void setIsTouchscreen(bool _isTouchscreen);
	bool getIsTouchscreen() const;

	void printFullInfo() const override;
	void printShortInfo() const override;
};