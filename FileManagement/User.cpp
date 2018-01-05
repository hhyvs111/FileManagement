#include"User.h"
//用户的构造函数
User::User()
{
}

User::~User()
{
}

bool User::Register(User user)
{
	if (user.userName == NULL)
		return false;
	userId = user.userId;
	strcpy(this->userName, user.userName);
	strcpy(this->userPassword, user.userPassword);
	cout << "注册成功" << endl;
	return true;
}

bool User::deleteUser(int userId)
{
	if (userId == 0)
		return false;
	//写一点数据库文件进去
}

