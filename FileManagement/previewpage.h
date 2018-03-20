#ifndef PREVIEWPAGE_H
#define PREVIEWPAGE_H

#include<QWebEnginePage>

class PreviewPage : public QWebEnginePage
{
    Q_OBJECT
public:
    explicit PreviewPage(QObject *parent = 0);
protected:
    bool acceptNavigationRequest(const QUrl&url, NavigationType type,bool isMainFrame);

signals:

public slots:
};

#endif // PREVIEWPAGE_H
