#include <iostream>
#include "IntCounter.h"

using namespace std;


int main(){
	/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/                  //memory leak test
	int* some_number = new int(5);
	IntCounter<int> first(some_number);
	cout << first.getCount() << endl;
	IntCounter<int> second = first;
	cout << first.getCount() << endl;

	{
		IntCounter<int> third(second);
		cout << first.getCount() << endl;
	}
	cout << first.getCount() << endl;
	cout << "The variable is: " << first.getValue() << endl;


	cout << endl;

	char* some_number2 = new char('x');
	IntCounter<char> first2(some_number2);
	cout << first2.getCount() << endl;
	IntCounter<char> second2 = first2;
	cout << first2.getCount() << endl;

	{
		IntCounter<char> third2(second2);
		cout << first2.getCount() << endl;
	}
	cout << first2.getCount() << endl;
	cout << "The variable is: " << first2.getValue() << endl;

	system("pause");
	return 0;
}

