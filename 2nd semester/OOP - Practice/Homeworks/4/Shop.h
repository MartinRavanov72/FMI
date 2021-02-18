#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Menu.h"

using namespace std;


class Shop{
private:
    string name;
	vector<User*> users;
	Menu* menu;
public:
	Shop();

	Shop(const string& _name, const vector<User*>& _users, Menu* _menu);

	Shop(const Shop& other);

	Shop& operator=(const Shop& other);

	~Shop();

	void setName(const string& _name);
	string getName() const;
	void setUsers(const vector<User*>& _users);
	vector<User*> getUsers() const;
	void setMenu(Menu* _menu);
	Menu* getMenu() const;

	void addUser(User* user);
	void deleteUser(User* user);
};
