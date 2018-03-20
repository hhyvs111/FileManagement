#include "previewpage.h"
#include <QDesktopServices>

PreviewPage::PreviewPage(QObject *parent) : QWebEnginePage(parent)
{

}

bool PreviewPage::acceptNavigationRequest(const QUrl &url, QWebEnginePage::NavigationType type, bool isMainFrame)
{
    Q_UNUSED(type)
    Q_UNUSED(isMainFrame)
    if(url.scheme() == QString("qrc")) return true;
    QDesktopServices::openUrl(url);
    return false;
}
