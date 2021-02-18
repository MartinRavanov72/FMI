#include <iostream> 
#include "IntCounter.h"

using namespace std;


IntCounter::IntCounter(){}

IntCounter::IntCounter(int* _num){
	this->setNum(_num);
	this->setCount(new int(1));
}

IntCounter::IntCounter(const IntCounter& other){
	this->setNum(other.getNum());
	this->setCount(other.getCount());
	*(this->getCount()) = *(this->getCount()) + 1;
}

IntCounter& IntCounter::operator=(const IntCounter& other){
	if(this == &other){
		return *this;
	}

	this->setNum(other.getNum());
	this->setCount(other.getCount());
	*(this->getCount()) = *(this->getCount()) + 1;
	
	return *this;
}

IntCounter::~IntCounter(){
	*(this->getCount()) = *(this->getCount()) - 1;
	
	if(*(this->getCount()) == 0){
		delete[] this->num;
		delete[] this->count;
	}
}

void IntCounter::setNum(int* _num){
	this->num = _num;
}

int* IntCounter::getNum() const{
	return this->num;
}

void IntCounter::setCount(int* _count){
	this->count = _count;
}

int* IntCounter::getCount() const{
	return this->count;
}