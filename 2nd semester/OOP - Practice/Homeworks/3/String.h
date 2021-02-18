#pragma once
#include <iostream>

using namespace std;


class String{
private:
	char* text = nullptr;
public:
	String();

	String(const char* _text);

	String(const String& other);

	String& operator=(const String& other);

	bool operator==(const String& other);

	bool operator!=(const String& other);

	friend String operator+(const String& left, const String& right);

	friend ostream& operator<<(ostream& out, const String& str);

	friend istream& operator>>(istream& in, String& str);

	char operator[](int position);

	bool operator<(const String& other);

	bool operator<=(const String& other);

	bool operator>(const String& other);

	bool operator>=(const String& other);

	String& operator+=(const String& other);

	~String();

	void setText(const char* _text);
	const char* getText() const;

	void append(char _symbol);
	void append(const String& _str);
	void append(const char* _text);
	void print() const;
	int length() const;
	bool contains(const String& _str) const;
	bool contains(char _char) const;
	char charAt(unsigned int index) const;
	int indexOf(char ch) const;
};
