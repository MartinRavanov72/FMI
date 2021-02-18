#pragma once
#include <iostream>

using namespace std;


class IntCounter{
	private:
	int* num = nullptr;
	int* count = nullptr;
	public:
	IntCounter();

	IntCounter(int* _num);

	IntCounter(const IntCounter& other);

	IntCounter& operator=(const IntCounter& other);

	~IntCounter();

	void setNum(int* _num);
	int* getNum() const;
	void setCount(int* _count);
	int* getCount() const;
};