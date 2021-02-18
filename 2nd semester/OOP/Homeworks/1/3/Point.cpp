#include <iostream> 
#include "Point.h"

using namespace std;


Point::Point(){
	this->setX(0);
	this->setY(0);
}

Point::Point(double _x, double _y){
	this->setX(_x);
	this->setY(_y);
}

Point::Point(const Point& other){
	this->setX(other.getX());
	this->setY(other.getY());
}

Point& Point::operator=(const Point& other){
	if(this == &other){
		return *this;
	}

	this->setX(other.getX());
	this->setY(other.getY());

	return *this;
}

Point::~Point(){
}

void Point::setX(double _x){
	this->x = _x;
}

double Point::getX() const{
	return this->x;
}

void Point::setY(double _y){
	this->y = _y;
}

double Point::getY() const{
	return this->y;
}