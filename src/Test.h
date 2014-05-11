#ifndef TEST_H
#define TEST_H

#include <QtWidgets>

class Test : public QGraphicsItem {
    QStringList sentence;
    QStringList words;
    QTextLayout layout;
	const QString gap = "...";
	
	QStringList sentence_in_use;

public:
    Test(QString sen, QString wor);
    ~Test();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	QStringList getWords();
    void relay();
    void todebug() const;
};

#endif
