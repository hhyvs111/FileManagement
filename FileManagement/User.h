#include "stdafx.h"
#pragma once
#ifndef USER_H_
class User
{
public:
	User();
	~User();
	bool Register(User user);
	bool deleteUser(int userId);
	bool updateUser(User user);
	bool findUserById(int userId);
	bool findUserByName(char* name);
	void getUser();

private:
	int userId;
	char* userName;
	char* userPassword;
	int phoneNumber;

};
#endif // USER_H_
