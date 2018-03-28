#pragma once
#ifndef DATABASE_H_
#define DATABASE_H_
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Database
{
public:
	Database();
	~Database();

	//连接数据库
	void connDB();

	//返回QStringList的查询结果
	static QList<QStringList> queryDB(const QString &Sql,int size);  
	//插入
	static bool insertDB(const QString &Sql);

	void createTable();

	//static bool deleteDB()
};

#endif // !DATABASE_H_


