#include <iostream>
#include "JSONObject.h"
#include "JSONArray.h"
#include "JSON.h"
#include <string>
#include <vector>

using namespace std;


int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);                  //memory leak test
	
	JSONObject<int> age("age", 29);
	JSONObject<char> gender("gender", 'm');

	JSONObject<string> name("name", "Ivan");
	JSONObject<string> zodiac("zodiac", "Pisces");
	JSONObject<string> uni("Uniersity", "SU");
	JSONObject<string> major("major", "SE");
	JSONObject<string> fullName("Full Name", "Vasil Troyanov Boyanov");
	JSONObject<string> friend1("friend1", "Suraikata");
	JSONObject<string> friend2("friend2", "Toni Storaro");
	JSONObject<string> friend3("friend3", "Djamaikata");
	JSONObject<string> friend4("friend4", "Sasho Romana");


	vector<JSON<string>*> jsonVectorTemp1;
	jsonVectorTemp1.push_back(&friend1);
	jsonVectorTemp1.push_back(&friend2);

	JSONArray<string> jsonArrayString1(jsonVectorTemp1);


	vector<JSON<string>*> jsonVectorTemp2;
	jsonVectorTemp2.push_back(&friend3);
	jsonVectorTemp2.push_back(&friend4);

	JSONArray<string> jsonArrayString2(jsonVectorTemp2);


	vector<JSON<string>*> jsonVectorTemp3;
	jsonVectorTemp3.push_back(&fullName);
	jsonVectorTemp3.push_back(&zodiac);
	jsonVectorTemp3.push_back(&uni);

	JSONArray<string> jsonArrayStringGeneral(jsonVectorTemp3);


	jsonArrayStringGeneral.addJsonObject(&major);
	jsonArrayStringGeneral.addJsonArray(&jsonArrayString1);
	jsonArrayStringGeneral.addJsonArray(&jsonArrayString2);


	cout << gender.getValue() << endl;
	cout << name.getValue() << endl << endl;
	jsonArrayStringGeneral.print();
	cout << endl;
	
	JSONObject<string> bestQuality("best quality", "meden glas");
	jsonArrayStringGeneral.addJsonObject(&bestQuality);

	cout << jsonArrayStringGeneral.getValueByKey("friend4") << endl << endl;

	jsonArrayStringGeneral.deleteElementByKey("friend2"); //will delete
	jsonArrayStringGeneral.deleteElementByKey("friend5"); //won't delete

	jsonArrayStringGeneral.print();

	system("pause");
	return 0;
}

