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
	QList<AccountInfo> accountInfo;
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
	int sum;
	for (int i = 0; i < accountInfo.size();i++)
	{

	}


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
