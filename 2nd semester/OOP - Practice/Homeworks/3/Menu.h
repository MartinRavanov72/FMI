#pragma once
#include <iostream> 
#include "String.h" 

using namespace std;


class Menu{
private:
	String aboutUs;
	String contacts;
	String ourTeamMembers;
public:
	Menu();

	Menu(const String& _aboutUs, const String& _contacts, const String& _ourTeamMembers);

	Menu(const Menu& other);

	Menu& operator=(const Menu& other);

	~Menu();

	void setAboutUs(const String& _aboutUs);
	String getAboutUs() const;
	void setContacts(const String& _contacts);
	String getContacts() const;
	void setOurTeamMembers(const String& _ourTeamMembers);
	String getOurTeamMembers() const;
};