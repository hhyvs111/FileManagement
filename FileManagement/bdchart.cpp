#include "bdchart.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "AccountInfo.h"

BDChart::BDChart(QObject *parent) : QObject(parent)
{

}

void BDChart::slot1(QString  data)
{

	QStringList listNumber = data.split("$");
	qDebug() << "adsadas" << listNumber[0].toInt();
	//插入数据到结构体


	QList<AccountInfo> accountInfo;		//容器中插入同样类型的结构体
	for (int i = 1; i <= listNumber[0].toInt(); i++)
	{
		AccountInfo account;
		QStringList accountList = listNumber[i].split("#");
		qDebug() << accountList;
		account.accountId = accountList[0].toInt();
		account.money = accountList[1].toInt();
		account.type = accountList[2];
		account.time = accountList[3];
		account.remark = accountList[4];
		account.name = accountList[5];
		accountInfo.append(account);
	}
	int sum = 0;
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	//每个种类的总金额

	for (int i = 0; i < accountInfo.size();i++)
	{
		if (accountInfo.at(i).type == "daily")
		{
			sum = sum + accountInfo.at(i).money;
		}
		if (accountInfo.at(i).type == "office")
		{
			sum1 = sum1 + accountInfo.at(i).money;
		}
		if (accountInfo.at(i).type == "funds")
		{	
			sum2 = sum2 + accountInfo.at(i).money;
		}
		if(accountInfo.at(i).type == "salary")
		{
			sum3 = sum3 + accountInfo.at(i).money;
		}
	}



	QJsonArray array;
	array.insert(0, QJsonValue(QString("材料")));
	array.insert(1, QJsonValue(QString("office")));
	array.insert(2, QJsonValue(QString("funds")));
	array.insert(3, QJsonValue(QString("salary")));

	QJsonArray arrayY;
	int a = 1000;
	arrayY.insert(0, QJsonValue(sum));
	arrayY.insert(1, QJsonValue(sum1));
	arrayY.insert(2, QJsonValue(sum2));
	arrayY.insert(3, QJsonValue(sum3));

	QJsonArray legend;
	legend.insert(0, QJsonValue(QString("1")));

	QJsonObject json;
	json.insert("xData", array);
	json.insert("yData", arrayY);
	json.insert("legend", legend);
	QJsonDocument document;
	document.setObject(json);
	emit signalTest(document.toJson(QJsonDocument::Compact));


}
void BDChart::slotTest()
{
	qDebug() << "send data bdchart" << endl;
	QJsonArray array;
	array.insert(0, QJsonValue(QString("materials")));
	array.insert(1, QJsonValue(QString("subsidy")));
	array.insert(2, QJsonValue(QString("3")));
	array.insert(3, QJsonValue(QString("4")));

	QJsonArray arrayY;
	int a = 1000;
	arrayY.insert(0, QJsonValue(a));
	arrayY.insert(1, QJsonValue(2000));
	arrayY.insert(2, QJsonValue(3000));
	arrayY.insert(3, QJsonValue(4000));

	QJsonArray legend;
	legend.insert(0, QJsonValue(QString("1")));

	QJsonObject json;
	json.insert("xData", array);
	json.insert("yData", arrayY);
	json.insert("legend", legend);
	QJsonDocument document;
	document.setObject(json);
	emit signalTest(document.toJson(QJsonDocument::Compact));
}

void BDChart::slotBack()
{
	qDebug() << "back" << endl;
}
