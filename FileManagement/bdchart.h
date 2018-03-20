#ifndef BDCHART_H
#define BDCHART_H

#include <QObject>
#include <QWidget>

class BDChart : public QObject
{
	Q_OBJECT
public:
	explicit BDChart(QObject *parent = 0);

signals:
	void signalTest(const QByteArray &message);

	public slots:
	void slotTest();
	void slot1();
	void slotBack();
};

#endif // BDCHART_H
