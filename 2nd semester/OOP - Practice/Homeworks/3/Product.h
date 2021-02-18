#pragma once
#include <iostream> 
#include "String.h"

using namespace std;


class Product{  //will be updated later to an abstract class, and the 3 other derived classes will actaully be used
private:
	int id = 0;
	double price = 0;
	String name;
	String shortDescription;
	String longDescription;
	int likes = 0;
protected:
	void setId(int _id);
public:
	Product();

	Product(int _id, double _price, const String& _name, const String& _shortDescription, const String& _longDescription);

	Product(const Product& other);

	Product& operator=(const Product& other);

	bool operator==(const Product& other);

	~Product();

	
	int getId() const;
	void setPrice(double _price);
	double getPrice() const;
	void setName(const String& _name);
	String getName() const;
	void setShortDescription(const String& _shortDescription);
	String getShortDescription() const;
	void setLongDescription(const String& _longDescription);
	String getLongDescription() const;
	void setLikes(int _likes);
	int getLikes() const;

	virtual void printFullInfo() const;
	virtual void printShortInfo() const;
	void addLike();
};