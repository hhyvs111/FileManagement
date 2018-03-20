#include "bdchart.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

BDChart::BDChart(QObject *parent) : QObject(parent)
{

}

void BDChart::slot1()
{

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
