#include <iostream>
#include "IntCounter.h"

using namespace std;


int main(){
	/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/                  //memory leak test
	int* some_number = new int(5);
	IntCounter first(some_number);
	cout << *(first.getCount()) << endl;
	IntCounter second = first;
	cout << *(first.getCount()) << endl;

	{
		IntCounter third(second);
		cout << *(first.getCount()) << endl;
	}
	cout << *(first.getCount()) << endl;

	system("pause");
	return 0;
}

