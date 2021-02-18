#include <iostream>
#include <cstring>
#include "MyString.h"

using namespace std;


MyString::MyString(){}

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

	this->setText(other.getText());

	return *this;
}

bool MyString::operator==(const MyString& other){
	char* newTextA = new char[strlen(this->getText()) + 1];
	strcpy_s(newTextA, strlen(this->getText()) + 1, this->getText());
	char* newTextB = new char[strlen(other.getText()) + 1];
	strcpy_s(newTextB, strlen(other.getText()) + 1, other.getText());

	int cnt = 0;
	while(*newTextA && *newTextA == *newTextB){       //main logic
		++newTextA;
		++newTextB;
		cnt++;
	}

	if((int)(unsigned char)(*newTextA) - (int)(unsigned char)(*newTextB) == 0){
		for(int i = 0; i < cnt; i++){
			newTextA--;       //reverse changes
			newTextB--;       //reverse changes
		}
		delete[] newTextA;
		delete[] newTextB;
		return true;
	}

	for(int i = 0; i < cnt; i++){
		newTextA--;       //reverse changes
		newTextB--;       //reverse changes
	}
	delete[] newTextA;
	delete[] newTextB;
	return false;
}

bool MyString::operator!=(const MyString& other){
	return !(*this == other);
}

bool MyString::operator<(const MyString& other){
	char* newTextA = new char[strlen(this->getText()) + 1];
	strcpy_s(newTextA, strlen(this->getText()) + 1, this->getText());
	char* newTextB = new char[strlen(other.getText()) + 1];
	strcpy_s(newTextB, strlen(other.getText()) + 1, other.getText());

	int cnt = 0;
	while(*newTextA && *newTextA == *newTextB){       //main logic
		++newTextA;
		++newTextB;
		cnt++;
	}

	if((int)(unsigned char)(*newTextA) - (int)(unsigned char)(*newTextB) < 0){
		for(int i = 0; i < cnt; i++){
			newTextA--;       //reverse changes
			newTextB--;       //reverse changes
		}
		delete[] newTextA;
		delete[] newTextB;
		return true;
	}

	for(int i = 0; i < cnt; i++){
		newTextA--;       //reverse changes
		newTextB--;       //reverse changes
	}
	delete[] newTextA;
	delete[] newTextB;
	return false;
}

bool MyString::operator>(const MyString& other){
	if(*this!=other){
		return !(*this < other);
	}
	return false;
	
}

MyString::~MyString(){
	delete[] this->text;
}

void MyString::setText(const char* _text){
	delete[] this->text;
	this->text = new char[strlen(_text) + 1];
	strcpy_s(this->text, strlen(_text) + 1, _text);
}

const char* MyString::getText() const{
	return this->text;
}

void MyString::append(char _symbol){
	if(this->text == nullptr){
		this->text = new char[1]{0};
		this->text[0] = _symbol;
	} else{
		int length = strlen(this->getText());
		char* textNew = new char[length+1]{0};

		for(int i = 0; i < length; i++){
			textNew[i] = this->text[i];
		}

		delete[] this->text;
		this->text = new char[length + 2]{0};

		for(int i = 0; i < length; i++){
			this->text[i] = textNew[i];
		}

		this->text[length] = _symbol;
		delete[] textNew;
	}
}

void MyString::append(const char* _text){
	if(this->text == nullptr){
		this->text = new char[strlen(_text) + 1];
		strcpy_s(this->text, strlen(_text) + 1, _text);
	} else{
		int currentLength = strlen(this->getText());
		int lengthOfNewText = strlen(_text);

		char* textNew = new char[currentLength + lengthOfNewText + 1]{0};
		for(int i = 0; i < currentLength; i++){
			textNew[i] = this->text[i];
		}

		delete[] this->text;
		this->text = new char[currentLength + lengthOfNewText + 1]{0};

		for(int i = 0; i < currentLength; i++){
			this->text[i] = textNew[i];
		}

		int cnt = 0;
		for(int i = currentLength; i < currentLength + lengthOfNewText; i++){
			this->text[i] = _text[cnt++];
		}
		delete[] textNew;
	}
}

void MyString::print() const{
	cout << this->getText() << endl;
}