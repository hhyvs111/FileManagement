#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include "Database.h"  

MySql::MySql(QObject *parent)
	:QObject(parent)
{
	dbDriver = "QMYSQL";
	dbName = "filemanagement";
	userName = "root";
	userPwd = "Tanwenbo520";
	hostName = "rm-wz93ilr9576g645y7yo.mysql.rds.aliyuncs.com";
	hostPort = 5432;
	connDB();
}

bool MySql::connDB()
{
		QSqlDatabase db;
		if (QSqlDatabase::contains("qt_sql_default_connection"))
			db = QSqlDatabase::database("qt_sql_default_connection");
		else
			db = QSqlDatabase::addDatabase(dbDriver);
		db.setHostName(hostName);//设置主机名
		db.setDatabaseName(dbName);//设置数据库名
		db.setUserName(userName);//设置用户名
		db.setPassword(userPwd);//设置用户密码

		if (db.open())
		{
			qDebug() << "Database connected successfully!";
			return true;
		}
		else
		{
			qDebug() << "Database connected failed!";
			return false;
		}
}

bool MySql::queryDB(const QString &Sql)
{
	QSqlQuery query;
	query.exec(Sql);
	if (query.next())
		//如果有记录则为真 否则退出判断
	{
		qDebug() << query.value(0).toString();
		return true;
	}
	return false;
}

bool MySql::insertDB(const QString &Sql)
{
	QSqlQuery insert;
	insert.exec(Sql);
	if (insert.isActive())
	{
		qDebug() << Sql;
		return true;
	}
	return false;
}
