#include <iostream> 
#include <cstring>
#include "Menu.h"

using namespace std;


Menu::Menu(){
}

Menu::Menu(const char* _aboutUs, const char* _contacts, const char* _ourTeamMembers){
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
	delete[] this->contacts;
	delete[] this->aboutUs;
	delete[] this->ourTeamMembers;
}

void Menu::setAboutUs(const char* _aboutUs){
	delete[] this->aboutUs;
	this->aboutUs = new char[strlen(_aboutUs) + 1];
	strcpy_s(this->aboutUs, strlen(_aboutUs) + 1, _aboutUs );
}

const char* Menu::getAboutUs() const{
	return this->aboutUs;
}

void Menu::setContacts(const char* _contacts){
	delete[] this->contacts;
	this->contacts = new char[strlen(_contacts) + 1];
	strcpy_s(this->contacts, strlen(_contacts) + 1, _contacts);
}

const char* Menu::getContacts() const{
	return this->contacts;
}

void Menu::setOurTeamMembers(const char* _ourTeamMembers){
	delete[] this->ourTeamMembers;
	this->ourTeamMembers = new char[strlen(_ourTeamMembers) + 1];
	strcpy_s(this->ourTeamMembers, strlen(_ourTeamMembers) + 1, _ourTeamMembers);
}

const char* Menu::getOurTeamMembers() const{
	return this->ourTeamMembers;
}