#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include <QStringList>

class SignCalender : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString info MEMBER m_info READ getInfo WRITE setInfo NOTIFY infoChanged)

    public:
        explicit SignCalender(QObject *parent = 0);

        QString getInfo() const;
        void setInfo(QString inf);

    signals:
        void infoChanged(QString);

    public slots:
        void callFromJS(QString info);
		void receiveSignInfo(QString);

    private:
        QStringList dateArray;
};


#endif // OBJECT_H 
