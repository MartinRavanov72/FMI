#pragma once
#include <iostream> 
#include <string>

using namespace std;


class Menu{
private:
	string aboutUs;
	string contacts;
	string ourTeamMembers;
public:
	Menu();

	Menu(const string& _aboutUs, const string& _contacts, const string& _ourTeamMembers);

	Menu(const Menu& other);

	Menu& operator=(const Menu& other);

	~Menu();

	void setAboutUs(const string& _aboutUs);
	string getAboutUs() const;
	void setContacts(const string& _contacts);
	string getContacts() const;
	void setOurTeamMembers(const string& _ourTeamMembers);
	string getOurTeamMembers() const;
};