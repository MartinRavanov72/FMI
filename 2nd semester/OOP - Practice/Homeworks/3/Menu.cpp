#include <iostream> 
#include "Menu.h"

using namespace std;


Menu::Menu(){
	
}

Menu::Menu(const String& _aboutUs, const String& _contacts, const String& _ourTeamMembers){
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

void Menu::setAboutUs(const String& _aboutUs){
	this->aboutUs = _aboutUs;
}

String Menu::getAboutUs() const{
	return this->aboutUs;
}

void Menu::setContacts(const String& _contacts){
	this->contacts = _contacts;
}

String Menu::getContacts() const{
	return this->contacts;
}

void Menu::setOurTeamMembers(const String& _ourTeamMembers){
	this->ourTeamMembers = _ourTeamMembers;
}

String Menu::getOurTeamMembers() const{
	return this->ourTeamMembers;
}