#include "buttondelegate.h"

#include <QApplication>
#include <QMouseEvent>
#include <QDialog>
#include <QPainter>
#include <QStyleOption>
#include <QDesktopWidget>
#include <qdebug.h>

ButtonDelegate::ButtonDelegate(QObject *parent) :
	QItemDelegate(parent)
{
}


//绘按钮？
void ButtonDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	//代理index一列，什么鬼，应该是基于列来实现的
	QStyleOptionButton* button = m_btns.value(index);
	if (!button) {
		button = new QStyleOptionButton();
		button->rect = option.rect.adjusted(4, 4, -4, -4);
		button->text = "下载";
		button->state |= QStyle::State_Enabled;

		(const_cast<ButtonDelegate *>(this))->m_btns.insert(index, button);
	}
	painter->save();

	if (option.state & QStyle::State_Selected) {
		painter->fillRect(option.rect, option.palette.highlight());

	}
	painter->restore();
	QApplication::style()->drawControl(QStyle::CE_PushButton, button, painter);


}

bool ButtonDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
	//按下
	if (event->type() == QEvent::MouseButtonPress) {

		QMouseEvent* e = (QMouseEvent*)event;

		if (option.rect.adjusted(4, 4, -4, -4).contains(e->x(), e->y()) && m_btns.contains(index)) {
			m_btns.value(index)->state |= QStyle::State_Sunken;
		}
		return true;
	}

	//鼠标事件？松开？
	if (event->type() == QEvent::MouseButtonRelease) {
		QMouseEvent* e = (QMouseEvent*)event;

		if (option.rect.adjusted(4, 4, -4, -4).contains(e->x(), e->y()) && m_btns.contains(index)) {
			m_btns.value(index)->state &= (~QStyle::State_Sunken);
			QString fileName = index.model()->data(index).toString();
			qDebug() << index<<fileName;
			QDialog *d = new QDialog();

			d->setGeometry(0, 0, 200, 200);
			d->move(QApplication::desktop()->screenGeometry().center() - d->rect().center());
			d->show();
			return true;
		}
	}
	return false;
}