#pragma once
#ifndef BUTTONDELEGATE_H
#define BUTTONDELEGATE_H

#include <QItemDelegate>

class ButtonDelegate : public QItemDelegate
{
	Q_OBJECT
public:
	explicit ButtonDelegate(QObject *parent = 0);

	//»æÍ¼£¿
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	//°´Å¥ÊÂ¼þ±à¼­
	bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

signals:

	public slots :

private:
	QMap<QModelIndex, QStyleOptionButton*> m_btns;

};

#endif // BUTTONDELEGATE_H