#include <iostream> 
#include <cmath> 
#include "Rectangle.h"

using namespace std;


Rectangle::Rectangle(){
}

Rectangle::Rectangle(const Point& _p1, const Point& _p2){
	if(_p1.getX() == _p2.getX() || _p1.getY() == _p2.getY() || (_p1.getX() == _p2.getX() && _p1.getY() == _p2.getY())){
		cout << "Invalid coordinates of the points!" << endl;
		return;
	}
	if(_p1.getY() > _p2.getY()){
		this->setP1(_p1);
		this->setP2(_p2);
	} else{
		this->setP1(_p2);
		this->setP2(_p1);
	}
}

Rectangle::Rectangle(const Rectangle& other){
	this->setP1(other.getP1());
	this->setP2(other.getP2());
}

Rectangle& Rectangle::operator=(const Rectangle& other){
	if(this == &other){
		return *this;
	}

	this->setP1(other.getP1());
	this->setP2(other.getP2());

	return *this;
}

Rectangle::~Rectangle(){
}

void Rectangle::setP1(const Point& _p1){
	this->p1 = _p1;
}

Point Rectangle::getP1() const{
	return this->p1;
}

void Rectangle::setP2(const Point& _p2){
	this->p2 = _p2;
}

Point Rectangle::getP2() const{
	return this->p2;
}

void addToList(const Rectangle& _rectangle, Rectangle** _list, int _length){
	if(_length == 0){
		if(*_list != nullptr){
			delete[] *_list;
		}
		*_list = new Rectangle[1];
		(*_list)[0] = _rectangle;
	} else{
		Rectangle* listNew = new Rectangle[_length + 1];

		for(int i = 0; i < _length; i++){
			listNew[i] = (*_list)[i];
		}

		delete[] *_list;
		*_list = new Rectangle[_length + 1];

		for(int i = 0; i < _length; i++){
			(*_list)[i] = listNew[i];
		}

		(*_list)[_length] = _rectangle;
		delete[] listNew;
	}
}

bool addToList(const Point& _p1, const Point& _p2, Rectangle** _list, int _length){
	if(_p1.getX() == _p2.getX() || _p1.getY() == _p2.getY() || (_p1.getX() == _p2.getX() && _p1.getY() == _p2.getY())){
		cout << "Invalid coordinates of the points!" << endl;
		return false;
	}
	if(_length == 0){
		if(*_list != nullptr){
			delete[] *_list;
		}

		*_list = new Rectangle[1];
		Rectangle rectangle(_p1, _p2);

		(*_list)[0] = rectangle;
		return true;
	} else{
		Rectangle* listNew = new Rectangle[_length + 1];
		for(int i = 0; i < _length; i++){
			listNew[i] = (*_list)[i];
		}

		delete[] *_list;
		*_list = new Rectangle[_length + 1];

		for(int i = 0; i < _length; i++){
			(*_list)[i] = listNew[i];
		}

		Rectangle rectangle(_p1, _p2);
		(*_list)[_length] = rectangle;
		delete[] listNew;
		return true;
	}
}

int getIndexOfLargestRectangle(Rectangle* _list, int _length){
	int indexOfLargestRectangle = -1;
	double biggestArea = 0;
	for(int i = 0; i < _length; i++){
		Rectangle rectangle = _list[i];
		double a = abs(rectangle.getP2().getX() - rectangle.getP1().getX());
		double b = abs(rectangle.getP1().getY() - rectangle.getP2().getY());

		double area = a * b;
		if(area >= biggestArea){
			indexOfLargestRectangle = i;
			biggestArea = area;
		}
	}
	return indexOfLargestRectangle;
}