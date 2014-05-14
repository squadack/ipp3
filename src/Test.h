#ifndef TEST_H
#define TEST_H

#include <QtWidgets>
#include "GraphicsView.h"

class Test : public QGraphicsObject {
	Q_OBJECT;
	
    QStringList sentence;
    QStringList words;
    QTextLayout layout;
	QList<int> gapy;
	const QString gap = "...";
	
	QStringList sentence_in_use;
    int lastidx;

	void wyliczgapy();
	QPoint wheregapbegins(int a);
public:
    Test(QString sen, QString wor);
    ~Test();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	int isWithinGap(const QPoint p);
	QStringList getWords();
    void relay();
    void todebug() const;
	
public slots:
	void considerdrop(QPoint pkt);
	void setgap(QString text);
signals:
	void dropaccepted();
    void gimmeString();
};

#endif
