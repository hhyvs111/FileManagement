#include "Database.h"
#include "stdafx.h"


Database::Database()
{
	

	connDB();
}

void Database::connDB()
{
	qDebug() << QSqlDatabase::drivers();
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
		createTable();
		// do something
	}
}
Database::~Database()
{

}

void Database::createTable()
{


	QSqlQuery sql_query;
	QString create_sql = "CREATE TABLE DownloadRecord (r_Id  INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,r_fileName  TEXT,r_filePath  TEXT,r_fileSize  TEXT,r_sumBlock  INTEGER,r_breakPoint  INTEGER,r_fileId  INTEGER); ";
	sql_query.prepare(create_sql);
	if (!sql_query.exec())
	{
		qDebug() << "Error: Fail to create table." << sql_query.lastError();
	}
	else
	{
		qDebug() << "Table created!";
	}
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
	qDebug() << Sql;
	QSqlQuery insert;
	insert.exec(Sql);
	if (insert.isActive())
	{
		qDebug() << Sql;
		return true;
	}
	return false;
}
