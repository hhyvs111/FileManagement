#include "Database.h"
#include "stdafx.h"


Database::Database()
{
	connDB();
}

void Database::connDB()
{
	QSqlDatabase database;
	if (QSqlDatabase::contains("qt_sql_default_connection"))
	{
		database = QSqlDatabase::database("qt_sql_default_connection");
	}
	else
	{
		database = QSqlDatabase::addDatabase("QSQLITE");
		database.setDatabaseName("MyDataBase.db");
		database.setUserName("fileManagement");
		database.setPassword("a13007351861");
	}

	if (!database.open())
	{
		qDebug() << "database open fail! " << database.lastError();
	}
	else
	{
		qDebug() << "database open success!";
		// do something
	}
}
Database::~Database()
{
}

QList<QStringList> Database::queryDB(const QString &Sql,int size)
{
	//size 是结果的列数
	qDebug() << Sql;

	QList<QStringList> datalist;
	QStringList data;
	QSqlQuery query;
	int cnt = 0;  
	query.exec(Sql);
	//qDebug() << "query.size();" << query.size();
	while (query.next())
	{
		while (cnt < size)
		{
			data << query.value(cnt).toString();
			//qDebug() << query.value(cnt).toString();
			cnt++;
		}

		datalist.append(data);
		cnt = 0;
		data.clear();
	}
	qDebug() << "the datalist size:" << datalist.size();
	return datalist;
}
bool Database::insertDB(const QString &Sql)
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
