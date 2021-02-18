#include "Shop.h"

Shop::Shop(){}

Shop::Shop(const string& _name, const vector<User*>& _users, Menu* _menu){
	this->setName(_name);
	this->setUsers(_users);
	this->setMenu(_menu);
}

Shop::Shop(const Shop& other){
	this->setName(other.getName());
	this->setUsers(other.getUsers());
	this->setMenu(other.getMenu());
}

Shop& Shop::operator=(const Shop& other){
	if(this == &other){
		return *this;
	}

	this->setName(other.getName());
	this->setUsers(other.getUsers());
	this->setMenu(other.getMenu());

	return *this;
}

Shop::~Shop(){}

void Shop::setName(const string& _name){
	this->name = _name;
}

string Shop::getName() const{
	return this->name;
}

void Shop::setUsers(const vector<User*>& _users){
	this->users = _users;
	int length = this->getUsers().size();
	for(int i = 0; i < length; i++){
		this->users[i]->logIn();
	}
}

vector<User*> Shop::getUsers() const{
	return this->users;
}

void Shop::setMenu(Menu* _menu){
	this->menu = _menu;
}

Menu* Shop::getMenu() const{
	return this->menu;
}

void Shop::addUser(User* user){
	int length = this->getUsers().size();
	bool hasSuchUser = false;
	for(int i = 0; i < length; i++){
		if(*(this->getUsers()[i]) == *user){
			hasSuchUser = true;
			break;
		}
	}
	if(!hasSuchUser){
		user->logIn();
		this->users.push_back(user);
	} else{
		cout << "There already is such a user" << endl;
	}
}

void Shop::deleteUser(User* user){
	int length = this->getUsers().size();
	for(int i = 0; i < length; i++){
		if(*(this->getUsers()[i]) == *user){
			this->users[i]->logOut();
			this->users.erase(this->users.begin() + i);
			return;
		}
	}
	cout << "No such user found" << endl;
}
