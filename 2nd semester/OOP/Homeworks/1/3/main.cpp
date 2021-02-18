#include <iostream>
#include "Point.h"
#include "Rectangle.h"

using namespace std;


int main(){
	/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/                  //memory leak test
	Rectangle* list = new Rectangle[1];
	Rectangle** listPtr = &list;
	int length = 0;

	Point p1(7, 3);
	Point p2(3, 6);
	bool isSuccessful = addToList(p1, p2, listPtr, length);
	if(isSuccessful){
		length++;
	}

	Point p3(-2, -11);
	Point p4(-7, -13);
	Rectangle rectangle(p3, p4);
	addToList(rectangle, listPtr, length++);

	Point p5(-1, 4);
	Point p6(3, -1);
	isSuccessful = addToList(p5, p6, listPtr, length);
	if(isSuccessful){
		length++;
	}

	Point p7(-1, 4);
	Point p8(-1, 4);
	isSuccessful = addToList(p7, p8, listPtr, length);
	if(isSuccessful){
		length++;
	}

	Point p9(-1, 4);
	Point p10(-1, -8);
	isSuccessful = addToList(p9, p10, listPtr, length);
	if(isSuccessful){
		length++;
	}

	cout << getIndexOfLargestRectangle(list, length) << endl;
	delete[] list;

	system("pause");
	return 0;
}