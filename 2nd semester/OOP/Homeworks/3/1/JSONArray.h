#pragma once
#include <iostream>
#include <memory>
#include "JSON.h"
#include <vector>
#include <string>

using namespace std;

template <class T>
class JSONArray : public JSON<T>{
	private:
	vector<JSON<T>*> array;
	public:
	JSONArray(){

	}

	JSONArray(const vector<JSON<T>*>& _array){
		this->setArray(_array);
	}

	JSONArray(const JSONArray<T>& other){
		this->setArray(other.getArray());
	}

	JSONArray& operator=(const JSONArray<T>& other){
		if(this == &other){
			return *this;
		}

		this->setArray(other.getArray());

		return *this;
	}

	~JSONArray(){

	}

	T getValueByKey(const string& _key) const{ //will throw exception if the key is invalid
		int length = this->array.size();
		for(int i = 0; i < length; i++){
			JSONObject<T>* objP = dynamic_cast<JSONObject<T>*>(this->array[i]);
			if(objP != NULL){
				if(_key == objP->getKey()){
					return objP->getValue();
				}
			} else{
				JSONArray<T>* arrP = dynamic_cast<JSONArray<T>*>(this->array[i]);
				try{
					T result = arrP->getValueByKey(_key);
					return result;
				} catch(const std::exception&){

				}
			}
		}
		throw invalid_argument("No such key!");
	}

	void deleteElementByKey(const string& _key){ //won't do anything if the key is invalid
		int length = this->array.size();
		for(int i = 0; i < length; i++){
			JSONObject<T>* objP = dynamic_cast<JSONObject<T>*>(this->array[i]);
			
			if(objP != NULL){
				if(_key == objP->getKey()){
					this->array.erase(this->array.begin() + i);
					return;
				}
			} else{
				JSONArray<T>* arrP = dynamic_cast<JSONArray<T>*>(this->array[i]);
				arrP->deleteElementByKey(_key);
			}
		}
	}

	void addJsonObject(JSONObject<T>* _element){
		this->array.push_back(_element);
	}

	void addJsonArray(JSONArray<T>* _array){
		this->array.push_back(_array);
	}

	void addJson(JSON<T>* _element){
		this->array.push_back(_element);
	}

	void setArray(const vector<JSON<T>*>& _array){
		this->array = _array;
	}

	vector<JSON<T>*> getArray() const{
		return this->array;
	}

	private:
	void print(int tabs) const{ //helper for the recursion, using the right amount of tabs
		int length = this->array.size();
		cout << "[" << endl;
		for(int i = 0; i < length; i++){
			for(int j = 0; j < tabs; j++){
				cout << '\t';
			}
			JSONObject<T>* objP = dynamic_cast<JSONObject<T>*>(this->array[i]);
			if(objP == NULL){
				JSONArray<T>* arrP = dynamic_cast<JSONArray<T>*>(this->array[i]);
				arrP->print(tabs + 1);
			} else{
				objP->print();
			}
			if(i != length - 1){
				cout << ",";
			}
			cout << endl;
		}
		for(int i = 0; i < tabs - 1; i++){
			cout << '\t';
		}
		cout << "]";
	}

	public:
	void print() const override{
		this->print(1);
		cout << endl;
	}
};