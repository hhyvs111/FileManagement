#pragma once
#ifndef DATABASE_H_
#define DATABASE_H_
#include <QSql>  
#include <QSqlDatabase>  
#include <QSqlQuery>  
#include <QDebug>  

class MySql
{
public:
	MySql();
	void initsql()
	{
		QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
		db.setHostName("127.0.0.1");
		db.setUserName("root");
		db.setPassword("123456");
		db.setDatabaseName("filemanagement");
		if (db.open())
		{
			qDebug() << "Database connected successfully!";
			return;
		}
		else
		{
			qDebug() << "Database connected failed!";
			return;
		}
		QSqlQuery q("", db);
		// 创建一个表
		q.exec("create table Names (id integer primary key, Firstname varchar, Lastname varchar, City varchar)");
		// 插入三条数据
		q.exec("insert into Names values (1, 'Christopher', 'Walker', 'Morristown')");
		q.exec("insert into Names values (2, 'Donald', 'Duck', 'Andeby')");
		q.exec("insert into Names values (3, 'Buck', 'Rogers', 'Paris')");
	}

	void createtable();
	bool loguser(QString name, QString passward);
	bool signup(QString name, QString passward);

private:
	QSqlQuery *query;
};
#endif // !DATABASE_H_
