#include "Menu.h"

using namespace std;


Menu::Menu(){
	
}

Menu::Menu(const string& _aboutUs, const string& _contacts, const string& _ourTeamMembers){
	this->setAboutUs(_aboutUs);
	this->setContacts(_contacts);
	this->setOurTeamMembers(_ourTeamMembers);
}

Menu::Menu(const Menu& other){
	this->setAboutUs(other.getAboutUs());
	this->setContacts(other.getContacts());
	this->setOurTeamMembers(other.getOurTeamMembers());
}

Menu& Menu::operator=(const Menu& other){
	if(this == &other){
		return *this;
	}

	this->setAboutUs(other.getAboutUs());
	this->setContacts(other.getContacts());
	this->setOurTeamMembers(other.getOurTeamMembers());

	return *this;
}

Menu::~Menu(){
}

void Menu::setAboutUs(const string& _aboutUs){
	this->aboutUs = _aboutUs;
}

string Menu::getAboutUs() const{
	return this->aboutUs;
}

void Menu::setContacts(const string& _contacts){
	this->contacts = _contacts;
}

string Menu::getContacts() const{
	return this->contacts;
}

void Menu::setOurTeamMembers(const string& _ourTeamMembers){
	this->ourTeamMembers = _ourTeamMembers;
}

string Menu::getOurTeamMembers() const{
	return this->ourTeamMembers;
}