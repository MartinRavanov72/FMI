#pragma once
#include <iostream>

using namespace std;


class Point{
	private:
	double x = 0;
	double y = 0;
	public:
	Point();

	Point(double _x, double _y);

	Point(const Point& other);

	Point& operator=(const Point& other);

	~Point();

	void setX(double _x);
	double getX() const;
	void setY(double _y);
	double getY() const;
};