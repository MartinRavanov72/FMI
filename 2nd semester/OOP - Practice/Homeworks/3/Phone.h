#pragma once
#include <iostream> 
#include "Product.h" 

using namespace std;


class Phone: public Product{
private:
	String make;
	double cameraMegapixel = 0;
	bool isTouchscreen = false;
public:
	Phone();

	Phone(int _id, double _price, const String& _name, const String& _shortDescription, const String& _longDescription, const String& _make, double _cameraMegapixel, bool _isTouchscreen);

	Phone(const Phone& other);

	Phone& operator=(const Phone& other);

	~Phone();

	void setMake(const String& _make);
	String getMake() const;
	void setCameraMegapixel(double _cameraMegapixel);
	double getCameraMegapixel() const;
	void setIsTouchscreen(bool _isTouchscreen);
	bool getIsTouchscreen() const;

	void printFullInfo() const override;
	void printShortInfo() const override;
};