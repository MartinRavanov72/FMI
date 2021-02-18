#pragma once
#include <iostream>
#include "User.h"
#include "Menu.h"
#include "Vector.h"

using namespace std;


class Shop{
private:
    String name;
	Vector<User*> users;
	Menu* menu;
public:
	Shop();

	Shop(const String& _name, const Vector<User*>& _users, Menu* _menu);

	Shop(const Shop& other);

	Shop& operator=(const Shop& other);

	~Shop();

	void setName(const String& _name);
	String getName() const;
	void setUsers(const Vector<User*>& _users);
	Vector<User*> getUsers() const;
	void setMenu(Menu* _menu);
	Menu* getMenu() const;

	void addUser(User* user);
	void deleteUser(User* user);
};
