#pragma once
#include <iostream>

using namespace std;

class Admin
{
private:
	string password;
	bool logged;
public:
	Admin();
	Admin(string password);
	void login();
	void logout();
	bool isLogged();
};

