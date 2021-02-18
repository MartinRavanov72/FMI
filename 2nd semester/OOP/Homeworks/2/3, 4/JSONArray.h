#pragma once
#include <iostream>
#include "JSONObject.h"
#include <fstream>

using namespace std;

template <class T>
class JSONArray{
	private:
	JSONObject<T>* array = nullptr;
	int length = 0;
	public:
	JSONArray(){
		this->array = nullptr;
		this->length = 0;
	}

	JSONArray(JSONObject<T>* _array, int _length){
		this->setLength(_length);
		this->setArray(_array, this->getLength());
	}

	JSONArray(const JSONArray& other){
		this->setLength(other.getLength());
		this->setArray(other.getArray(), this->getLength());
		
	}

	JSONArray& operator=(const JSONArray& other){
		if(this == &other){
			return *this;
		}

		delete[] this->array;

		this->setLength(other.getLength());
		this->setArray(other.getArray(), this->getLength());

		return *this;
	}

	~JSONArray(){
		delete[] this->array;
	}

	T getValueByKey(const char* _key) const{
		int length = this->getLength();
		for(int i = 0; i < length; i++){
			if(strcmp(this->getArray()[i].getKey(), _key) == 0){
				return this->getArray()[i].getValue();
			}
		}
		throw invalid_argument("No such key!");
	}

	void deleteElementByKey(const char* _key){
		int length = this->getLength();
		if(length == 1){
			const char* keyOfOnlyElement = this->getArray()[0].getKey();
			if(strcmp(keyOfOnlyElement, _key) == 0){
				delete[] this->array;
				this->setLength(0);
				this->array = nullptr;
			} else{
				throw invalid_argument("No such key!");
			}
			
		} else{
			JSONObject<T>* arrayNew = new JSONObject<T>[length - 1];
			int cnt = 0;
			bool isFound = false;
			for(int i = 0; i < length; i++){
				const char* keyOfCurrentElement = this->getArray()[i].getKey();
				if(strcmp(keyOfCurrentElement, _key) == 0){
					isFound = true;
				} else{
					if(!isFound && i == length - 1){
						throw invalid_argument("No such key!");
					}
					arrayNew[cnt] = this->array[i];
					cnt++;
				}
			}
			if(!isFound){
				throw invalid_argument("No such key!");
			}
			delete[] this->array;

			this->array = new JSONObject<T>[length - 1];
			for(int i = 0; i < length - 1; i++){
				this->array[i] = arrayNew[i];
			}
			this->setLength(this->getLength() - 1);

			delete[] arrayNew;
		}
	}

	void addElement(const JSONObject<T>& _element){
		if(this->array == nullptr){
			this->array = new JSONObject<T>[1];
			this->array[0] = _element;
			this->setLength(1);
		} else{
			int length = this->getLength();
			JSONObject<T>* arrayNew = new JSONObject<T>[length + 1];
			for(int i = 0; i < length; i++){
				arrayNew[i] = this->array[i];
			}

			delete[] this->array;
			this->array = new JSONObject<T>[length + 1];
			for(int i = 0; i < length; i++){
				this->array[i] = arrayNew[i];
			}
			this->array[length] = _element;
			this->setLength(this->getLength() + 1);

			delete[] arrayNew;
		}
	}

	void addElement(const char* _key, const T& _value){
		JSONObject<T> jsonObject(_key, _value);
		this->addElement(jsonObject);
	}

	void setArray(JSONObject<T>* _array, int _length){
		if(_length < 0){
			throw invalid_argument("Length cannot be < 0");
		}
		delete[] this->array;
		this->array = new JSONObject<T>[_length];
		for(int i = 0; i < _length; i++){
			this->array[i] = _array[i];
		}
	}

	JSONObject<T>* getArray() const{
		return this->array;
	}

	void setLength(int _length){
		if(_length < 0){
			throw invalid_argument("Length cannot be < 0");
		}
		this->length = _length;
	}

	int getLength() const{
		return this->length;
	}

	void writeToFile(const char* _fileName) const{  //task 4
		fstream fileOUT(_fileName, ios::out | ios::app);

		int length = this->getLength();
		for(int i = 0; i < length; i++){
			fileOUT << "\"" << this->getArray()[i].getKey() << "\"" << ": " << this->getArray()[i].getValue() << endl;
		}

		cout << "Info in file written." << endl;

		fileOUT.close(); 
	}
};