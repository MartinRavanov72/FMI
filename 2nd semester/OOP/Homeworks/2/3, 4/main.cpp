#include <iostream>
#include "JSONObject.h"
#include "JSONArray.h"

using namespace std;


int main(){
	/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/                  //memory leak test
	
	JSONObject<int> age("age", 29);
	JSONObject<char> gender("gender", 'm');

	JSONObject<bool> hasDrinkingProblems("hasDrinkingProblems", true);

	JSONObject<bool> hasDriversLicense("hasDriversLicense", true);
	JSONObject<bool> hasCreditCard("hasCreditCard", true);
	JSONObject<bool> hasGirlfriend("hasGirlfriend", false);
	JSONObject<bool> smokes("smokes", false);

	JSONObject<bool>* jsonObjectArrayTemp = new JSONObject<bool>[3];
	jsonObjectArrayTemp[0] = hasDriversLicense;
	jsonObjectArrayTemp[1] = hasCreditCard;
	jsonObjectArrayTemp[2] = hasGirlfriend;

	JSONArray<bool> jsonArrayBool(jsonObjectArrayTemp, 3);
	jsonArrayBool.addElement(smokes);

	cout << gender.getValue() << endl;
	cout << hasDrinkingProblems.getValue() << endl;
	cout << jsonArrayBool.getArray()[3].getKey() << endl;
	cout << jsonArrayBool.getLength() << endl;

	jsonArrayBool.writeToFile("info.txt");

	jsonArrayBool.addElement("isCool", false);

	cout << jsonArrayBool.getValueByKey("smokes") << endl;

	jsonArrayBool.deleteElementByKey("smokes");

	jsonArrayBool.writeToFile("info.txt");

	delete[] jsonObjectArrayTemp;

	system("pause");
	return 0;
}

