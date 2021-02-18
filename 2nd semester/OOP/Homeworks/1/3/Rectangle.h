#pragma once
#include <iostream>
#include "Point.h"

using namespace std;


class Rectangle{
	private:
	Point p1;
	Point p2;
	public:
	Rectangle();

	Rectangle(const Point& _p1, const Point& _p2);

	Rectangle(const Rectangle& other);

	Rectangle& operator=(const Rectangle& other);

	~Rectangle();

	void setP1(const Point& _p1);
	Point getP1() const;
	void setP2(const Point& _p2);
	Point getP2() const;
	friend void addToList(const Rectangle& _rectangle, Rectangle** _list, int _length);
	friend bool addToList(const Point& _p1, const Point& _p2, Rectangle** _list, int _length);
	friend int getIndexOfLargestRectangle(Rectangle* _list, int _length);
};