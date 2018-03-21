#include "SignCalender.h"
#include <QDebug>
#include <QString>
#include <QVector>


SignCalender::SignCalender(QObject *parent): QObject(parent) {
	dateArray.push_back("2018-03-01");
	dateArray.push_back("2018-03-02");
	dateArray.push_back("2018-03-04");
	dateArray.push_back("2018-03-06");
}

void SignCalender::receiveSignInfo(QString data)
{


	//QStringList listNumber = data.split("#");
	//for (int i = 0; i < listNumber.size(); i++)
	//{
	//	qDebug() << listNumber.at(i);
	//	dateArray.push_back(listNumber.at(i));
	//}

}

QString SignCalender::getInfo() const {
    return dateArray.join(",");
}

void SignCalender::setInfo(QString inf) {
    dateArray = inf.split(",");
}

void SignCalender::callFromJS(QString info) {
    qDebug("called");
    qDebug() << info;
}
