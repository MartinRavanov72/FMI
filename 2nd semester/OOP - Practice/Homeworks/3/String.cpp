#include <iostream>
#include "String.h"

using namespace std;


String::String(){
	this->text = new char[1];
	this->text[0] = '\0';
}

String::String(const char* _text){
	this->setText(_text);
}

String::String(const String& other){
	this->setText(other.getText());
}

String& String::operator=(const String& other){
	if(this == &other){
		return *this;
	}

	this->setText(other.getText());

	return *this;
}

bool String::operator==(const String& other){
	if(strcmp(this->getText(), other.getText()) == 0){
		return true;
	}
	return false;
}

bool String::operator!=(const String& other){
	return !(*this == other);
}

bool String::operator<=(const String& other){
	if(strcmp(this->getText(), other.getText()) <= 0){
		return true;
	}
	return false;
}

bool String::operator<(const String& other){
	if(strcmp(this->getText(), other.getText()) < 0){
		return true;
	}
	return false;
}

bool String::operator>=(const String& other){
	if(strcmp(this->getText(), other.getText()) >= 0){
		return true;
	}
	return false;
}

bool String::operator>(const String& other){
	if(strcmp(this->getText(), other.getText()) > 0){
		return true;
	}
	return false;
}

ostream& operator<<(ostream& out, const String& str){
	out << str.getText();
	return out;
}

istream& operator>>(istream& in, String& str){
	char* temp = new char[1000]{0};
	in.getline(temp, 1000);
	str.setText(temp);
	delete[] temp;

	return in;
}

String operator+(const String& left, const String& right){
	String str = left;
	str.append(right);

	return str;
}


char String::operator[](int position){
	return this->charAt(position);
}


String& String::operator+=(const String& other){
	this->append(other.getText());
	return *this;
}

String::~String(){
	delete[] this->text;
}

void String::setText(const char* _text){
	delete[] this->text;
	int length = strlen(_text);
	this->text = new char[length + 1];
	strcpy_s(this->text, length + 1, _text);
	this->text[length] = '\0';
}

const char* String::getText() const{
	return this->text;
}

void String::append(char _symbol){
	int length = strlen(this->getText());
	char* newText = new char[length + 2];
	strcpy_s(newText, length + 1, this->text);
	newText[length] = _symbol;
	newText[length + 1] = '\0';
	delete[] this->text;
	this->text = newText;
}

void String::append(const char* _text){
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

void String::append(const String& _str){
	this->append(_str.getText());
}

bool String::contains(const String& str) const{
	int thisLength = this->length();
	int otherLength = str.length();
	if(otherLength > thisLength){
		return false;
	}
		
	for(int i = 0; i < thisLength; i++){
		int j = 0;
		if(this->charAt(i) == str.charAt(j)){
			int k = i;
			while(this->charAt(i) == str.charAt(j) && j < otherLength){
				j++;
				i++;
			}
			if(j == otherLength){
				return true;
			} else{
				i = k;
			}
		}
	}
	return false;
}

bool String::contains(char _char) const{
	int length = this->length();
	for(int i = 0; i < length; i++){
		if(this->getText()[i] == _char){
			return true;
		}
	}
	return false;
}

void String::print() const{
	cout << this->getText() << endl;
}

int String::length() const{
	return strlen(this->getText());
}

char String::charAt(unsigned int _index) const{
	if(_index >= this->length()){
		return '\0';
	}
	return this->getText()[_index];
}

int String::indexOf(char ch) const{
	int index = -1;
	for(int i = 0; i < this->length(); i++){
		if(this->charAt(i) == ch){
			index = i;
			break;
		}
	}
	return index;
}