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
	void setUser();
	void getUser();

private:
	int userId;
	string userName;
	string userPassword;
	string userBrithday;
	
};
#endif // USER_H_
