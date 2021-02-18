#include <iostream>
#include <cstring>
#include "MyString.h"

using namespace std;


MyString::MyString(){
	this->text = new char[1];
	this->text[0] = '\0';
}

MyString::MyString(const char* _text){
	this->setText(_text);
}

MyString::MyString(const MyString& other){
	this->setText(other.getText());
}

MyString& MyString::operator=(const MyString& other){
	if(this == &other){
		return *this;
	}

	delete[] this->text;

	this->setText(other.getText());

	return *this;
}

bool MyString::operator==(const MyString& other){
	if(strcmp(this->getText(), other.getText()) == 0){
		return true;
	}
	return false;
}

bool MyString::operator!=(const MyString& other){
	return !(*this == other);
}

bool MyString::operator<(const MyString& other){
	if(strcmp(this->getText(), other.getText()) < 0){
		return true;
	}
	return false;
}

bool MyString::operator>(const MyString& other){
	if(*this!=other){
		return !(*this < other);
	}
	return false;
}

ostream& operator<<(ostream& out, const MyString& str){
	out << str.getText();
	return out;
}

istream& operator>>(istream& in, MyString& str){
	char* temp = new char[1000]{0};
	in.getline(temp, 1000);
	str.setText(temp);
	delete[] temp;
	
	return in;
}

MyString::~MyString(){
	delete[] this->text;
}

void MyString::setText(const char* _text){
	delete[] this->text;
	int length = strlen(_text);
	this->text = new char[length + 1];
	strcpy_s(this->text, length + 1, _text);
	this->text[length] = '\0';
}

const char* MyString::getText() const{
	return this->text;
}

void MyString::append(char _symbol){
	int length = strlen(this->getText());
	char* newText = new char[length + 2];
	strcpy_s(newText, length + 1, this->text);
	newText[length] = _symbol;
	newText[length + 1] = '\0';
	delete[] this->text;
	this->text = newText;
}

void MyString::append(const char* _text){
	int currentLength = strlen(this->getText());
	int addedLength = strlen(_text);
	char* newText = new char[currentLength + addedLength + 1];
	strcpy_s(newText, currentLength + 1, this->text);
	for(int i = currentLength; i < currentLength + addedLength; i++){
		newText[i] = _text[i - currentLength];
	}
	newText[currentLength + addedLength] = '\0';
	delete[] this->text;
	this->text = newText;
}

void MyString::print() const{
	cout << this->getText() << endl;
}