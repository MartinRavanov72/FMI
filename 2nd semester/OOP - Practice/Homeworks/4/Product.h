#pragma once
#include <iostream> 
#include <string>

using namespace std;


class Product{
private:
	int id = 0;
	double price = 0;
	string name;
	string shortDescription;
	string longDescription;
	int likes = 0;
protected:
	void setId(int _id);
public:
	Product();

	Product(int _id, double _price, const string& _name, const string& _shortDescription, const string& _longDescription);

	Product(const Product& other);

	Product& operator=(const Product& other);

	bool operator==(const Product& other);

	~Product();

	
	int getId() const;
	void setPrice(double _price);
	double getPrice() const;
	void setName(const string& _name);
	string getName() const;
	void setShortDescription(const string& _shortDescription);
	string getShortDescription() const;
	void setLongDescription(const string& _longDescription);
	string getLongDescription() const;
	void setLikes(int _likes);
	int getLikes() const;

	virtual void printFullInfo() const;
	virtual void printShortInfo() const;
	void addLike();
};