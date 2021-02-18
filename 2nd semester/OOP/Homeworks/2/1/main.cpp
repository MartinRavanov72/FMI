#include <iostream>
#include "MyString.h"

using namespace std;


int main(){
	/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); */                 //memory leak test
	MyString temp("asd");
	MyString str;
	cin >> str;
	cout << str << endl;
	cin.clear();
	cin >> str;
	cout << str << endl;

	temp.print();
	temp.append('!');
	temp.print();
	temp.append("!!");
	temp.append("");
	temp.print();

	bool a = MyString("aaa") < MyString("bb");

	bool b = MyString("AAA") == MyString("aaa");

	bool c = MyString("aaa") == MyString("aaa");

	bool d = MyString("aa") < MyString("aaa");

	bool e = MyString("aaa") != MyString("aa");

	bool f = MyString("aaab") > MyString("aaac");

	bool g = MyString("") > MyString("a");

	bool h = MyString("aa") > MyString("aa");

	bool i = MyString("aa") < MyString("aa");

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;
	cout << g << endl;
	cout << h << endl;
	cout << i << endl;

	system("pause");
	return 0;
}