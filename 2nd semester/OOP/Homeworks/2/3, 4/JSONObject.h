#pragma once
#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class JSONObject{
	private:
	char* key = nullptr;
	T value;
	public:
	JSONObject(){
		this->key = nullptr;
	}

	JSONObject(const char* _key, const T& _value){
		this->setKey(_key);
		this->setValue(_value);
	}

	JSONObject(const JSONObject& other){
		this->setKey(other.getKey());
		this->setValue(other.getValue());
	}

	JSONObject& operator=(const JSONObject& other){
		if(this == &other){
			return *this;
		}

		delete[] this->key;

		this->setKey(other.getKey());
		this->setValue(other.getValue());

		return *this;
	}

	~JSONObject(){
		delete[] this->key;
	}

	void setKey(const char* _key){
		delete[] this->key;
		int length = strlen(_key);
		this->key = new char[length + 1];
		strcpy_s(this->key, length + 1, _key);
		this->key[length] = '\0';
	}

	const char* getKey() const{
		return this->key;
	}

	void setValue(const T& _value){
		this->value = _value;
	}

	T getValue() const{
		return this->value;
	}
};