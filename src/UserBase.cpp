#include "UserBase.h"

UserBase::UserBase()
{
	try
	{
		usrBase = new std::vector<User>;
	}
	catch (std::bad_alloc& ex)
	{
		cout << "ERROR: caught bad_alloc: " << ex.what() << endl;
	}
	User admin("Administartor", "admin", sha256("admin2023"));
	addUsers(admin);
}

UserBase::~UserBase()
{
	delete usrBase;
}

void UserBase::showUsers()
{
	cout << setw(17) << "ID пользовател¤" << setw(20) << "»м¤ пользовател¤" << setw(10) << "Ћогин" << endl;
	for (int i = 0; i < usrBase->size(); i++)
	{
		cout << setw(17) << i << setw(20) << usrBase->at(i).name << setw(10) << usrBase->at(i).login << endl;
	}
}

void UserBase::addUsers(const char name[], const char login[], const char pwd[])
{
	string sname = name;
	string slogin = login;
	string spwd = pwd;
	addUsers(sname, slogin, spwd);
}

void UserBase::addUsers(string& name, string& login, string& pwd)
{
	string pwdsha = sha256(pwd);
	User newUser(name, login, pwdsha);
	addUsers(newUser);
}

void UserBase::addUsers(User& usrStr)
{
	usrBase->push_back(usrStr);
}

void UserBase::chgPwd(int userId, string& pwd)
{
	usrBase->at(userId).pwd = sha256(pwd);
}

int UserBase::getUserCount()
{
	return usrBase->size();
}

int UserBase::getUserId(string& login)
{
	for (int i = 0; i < usrBase->size(); i++)
	{
		if (usrBase->at(i).login == login)
		{
			return i;
		}
	}
	return -1;
}

string UserBase::getUserName(int userId)
{
	return usrBase->at(userId).name;
}

void UserBase::delUser(int userId)
{
	usrBase->erase(usrBase->begin() + userId);
}

bool UserBase::loginCheck(string& login)
{
	for (int i = 0; i < usrBase->size(); i++)
	{
		if (usrBase->at(i).login == login)
		{
			return true;
		}
	}
	return false;
}

bool UserBase::pwdCheck(int userId, string& pwd)
{
	string temp = sha256(pwd);
	if (usrBase->at(userId).pwd == temp)
	{
		return true;
	}
	else
	{
		return false;
	}
}