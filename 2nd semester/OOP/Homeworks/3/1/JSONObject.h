#pragma once
#include <iostream>
#include "JSON.h"
#include <string>

using namespace std;

template <class T>
class JSONObject : public JSON<T>{
	private:
	string key;
	T value;
	public:
	JSONObject(){

	}

	JSONObject(const string& _key, const T& _value){
		this->setKey(_key);
		this->setValue(_value);
	}

	JSONObject(const JSONObject<T>& other){
		this->setKey(other.getKey());
		this->setValue(other.getValue());
	}

	JSONObject& operator=(const JSONObject<T>& other){
		if(this == &other){
			return *this;
		}

		this->setKey(other.getKey());
		this->setValue(other.getValue());

		return *this;
	}

	~JSONObject(){

	}

	void setKey(const string& _key){
		this->key = _key;
	}

	string getKey() const{
		return this->key;
	}

	void setValue(const T& _value){
		this->value = _value;
	}

	T getValue() const{
		return this->value;
	}

	void print() const override{
		cout << "\"" << this->getKey() << "\"" << " : \"" << this->getValue() << "\"";
	}
};