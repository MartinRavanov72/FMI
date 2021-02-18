#pragma once
#include <iostream> 

using namespace std;


class Menu{
	private:
	char* aboutUs = nullptr;
	char* contacts = nullptr;
	char* ourTeamMembers = nullptr;
	public:
	Menu();

	Menu(const char* _aboutUs, const char* _contacts, const char* ourTeamMembers);

	Menu(const Menu& other);

	Menu& operator=(const Menu& other);

	~Menu();

	void setAboutUs(const char* _aboutUs);
	const char* getAboutUs() const;
	void setContacts(const char* _contacts);
	const char* getContacts() const;
	void setOurTeamMembers(const char* _ourTeamMembers);
	const char* getOurTeamMembers() const;
};