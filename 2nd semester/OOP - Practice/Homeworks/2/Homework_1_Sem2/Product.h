#pragma once
#include <iostream> 

using namespace std;


class Product{
	private:
	int id;
	double price;
	char* name = nullptr;
	char* shortDescription = nullptr;
	char* longDescription = nullptr;
	int likes = 0;
	public:
	Product();

	Product(int _id, double _price, const char* _name, const char* _shortDescription, const char* _longDescription);

	Product(const Product& other);

	Product& operator=(const Product& other);

	bool operator==(const Product& other);

	~Product();

	void setId(int _id);
	int getId() const;
	void setPrice(double _price);
	double getPrice() const;
	void setName(const char* _name);
	const char* getName() const;
	void setShortDescription(const char* _shortDescription);
	const char* getShortDescription() const;
	void setLongDescription(const char* _longDescription);
	const char* getLongDescription() const;
	void setLikes(int _likes);
	int getLikes() const;

	void printFullInfo() const;
	void printShortInfo() const;
	void addLike();
};