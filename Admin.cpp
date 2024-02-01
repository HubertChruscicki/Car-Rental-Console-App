#include "Admin.h"

Admin::Admin()
{
	this->logged = false;
}

Admin::Admin(string password)
{
	this->password = password;
	this->logged = false;
}

void Admin::login()
{
	string password;

	system("cls");

	cout << "Input password: ";
	cin >> password;

	if(password==this->password)
	{
		this->logged = true;
	}
	else
	{
		cout << "wrong password"<<endl;
		system("pause");
	}
}

void Admin::logout()
{
	this->logged = false;
}

bool Admin::isLogged()
{
	if(this->logged==true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
