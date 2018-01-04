#pragma once
#include "stdafx.h"
#ifdef USER_H_
class User
{
public:
	bool Register(User user);
	bool deleteUser(int userId);
	bool updateUser(User user);
	void setUser();
	void getUser();

private:
	int userId;
	String userName;
	String userPassword;

	
};
#endif // USER_H_
