#pragma once
#include <iostream>

using namespace std;

template <class T>
class IntCounter{
	private:
	T* value = nullptr;
	int* count = nullptr;

	void setValue(T* _value){
		this->value = _value;
	}

	void setCount(int* _count){
		this->count = _count;
	}

	T* getValuePointer() const{
		return this->value;
	}

	int* getCountPointer() const{
		return this->count;
	}

	public:
	IntCounter(){
		this->setValue(nullptr);
		this->setCount(nullptr);
	}

	IntCounter(T * _value){
		this->setValue(_value);
		this->setCount(new int(1));
	}

	IntCounter(const IntCounter& other){
		this->setValue(other.getValuePointer());
		this->setCount(other.getCountPointer());
		*(this->count) = *(this->count) + 1;
	}

	IntCounter& operator=(const IntCounter& other){
		if(this == &other){
			return *this;
		}

		delete this->value;
		delete this->count;

		this->setValue(other.getValuePointer());
		this->setCount(other.getCountPointer());
		*(this->count) = *(this->count) + 1;

		return *this;
	}

	~IntCounter(){
		*(this->count) = *(this->count) - 1;

		if(this->getCount() == 0){
			delete this->value;
			delete this->count;
		}
	}

	const T getValue() const{
		return *(this->value);
	}

	const int getCount() const{
		return *(this->count);
	}
};