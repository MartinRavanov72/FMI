#pragma once
#include <iostream>

using namespace std;


class MyString{
	private:
	char* text = nullptr;
	public:
	MyString();

	MyString(const char* _text);

	MyString(const MyString& other);

	MyString& operator=(const MyString& other);

	bool operator==(const MyString& other);

	bool operator!=(const MyString& other);

	bool operator<(const MyString& other);

	bool operator>(const MyString& other);

	~MyString();

	void setText(const char* _text);
	const char* getText() const;
	void append(char _symbol);
	void append(const char* _text);
	void print() const;
};