#ifndef Echarts_H
#define Echarts_H

#include <QWidget>
#include<QHBoxLayout>
#include "bdchart.h"
class QWebEngineView;
class BDChart;
class WebSocketClientWrapper;
class QWebChannel;
class QWebSocketServer;

namespace Ui {
	class Echarts;
}
class Echarts : public QWidget
{
	Q_OBJECT
public:
	explicit Echarts(QWidget *parent = 0);
	~Echarts();
	void onimportexcel();
	public slots:
	//void importexcel();
	void choosefilepath();
	void exportexcel();
signals:
	void signalTest(const QByteArray &message);
private:
	void connects();

private:
	Ui::Echarts *ui;
	QWebEngineView *mWebView;
	BDChart *mChartManager;
	WebSocketClientWrapper *mWebSocketClientWrapper;
	QWebChannel *channel;
	QWebSocketServer* mServer;
};

#endif // Echarts_H
