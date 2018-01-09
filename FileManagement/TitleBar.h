#pragma once
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

enum ButtonType
{
	MIN_BUTTON = 0,         // ��С���͹رհ�ť;
	MIN_MAX_BUTTON,        // ��С������󻯺͹رհ�ť;
	ONLY_CLOSE_BUTTON       // ֻ�йرհ�ť;
};

class TitleBar : public QWidget
{
	Q_OBJECT

public:
	TitleBar(QWidget *parent);
	//����parentû�и�Ĭ��ֵNULL����֤�ڴ���TitleBar����ʱ��ָ�����ø�ֵ;�Ҹ�ֵ��ΪNULL;
	~TitleBar();

	// ���ñ���������ɫ;
	void setBackgroundColor(int r, int g, int b);
	// ���ñ�����ͼ��;
	void setTitleIcon(QString filePath, QSize IconSize = QSize(25, 25));
	// ���ñ�������;
	void setTitleContent(QString titleContent, int titleFontSize = 9);
	// ���ñ���������;
	void setTitleWidth(int width);
	// ���ñ������ϰ�ť����;
	void setButtonType(ButtonType buttonType);
	// ���ñ������еı����Ƿ�����;������Կ�Ч��;
	void setTitleRoll();
	// ���ô��ڱ߿����;
	void setWindowBorderWidth(int borderWidth);

	// ����/��ȡ ���ǰ���ڵ�λ�ü���С;
	void saveRestoreInfo(const QPoint point, const QSize size);
	void getRestoreInfo(QPoint& point, QSize& size);

private:
	void paintEvent(QPaintEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	// ��ʼ���ؼ�;
	void initControl();
	// �źŲ۵İ�;
	void initConnections();
	// ������ʽ�ļ�;
	void loadStyleSheet(const QString &sheetName);

signals:
	// ��ť�������ź�;
	void signalButtonMinClicked();
	void signalButtonRestoreClicked();
	void signalButtonMaxClicked();
	void signalButtonCloseClicked();

	private slots:
	// ��ť�����Ĳ�;
	void onButtonMinClicked();
	void onButtonRestoreClicked();
	void onButtonMaxClicked();
	void onButtonCloseClicked();
	void onRollTitle();

private:
	QLabel* m_pIcon;                    // ������ͼ��;
	QLabel* m_pTitleContent;            // ����������;
	QPushButton* m_pButtonMin;          // ��С����ť;
	QPushButton* m_pButtonRestore;      // ��󻯻�ԭ��ť;
	QPushButton* m_pButtonMax;          // ��󻯰�ť;
	QPushButton* m_pButtonClose;        // �رհ�ť;

										// ����������ɫ;
	int m_colorR;
	int m_colorG;
	int m_colorB;

	// ��󻯣���С������;
	QPoint m_restorePos;
	QSize m_restoreSize;
	// �ƶ����ڵı���;
	bool m_isPressed;
	QPoint m_startMovePos;
	// ������������Ч��ʱ��;
	QTimer m_titleRollTimer;
	// ����������;
	QString m_titleContent;
	// ��ť����;
	ButtonType m_buttonType;
	// ���ڱ߿����;
	int m_windowBorderWidth;
};