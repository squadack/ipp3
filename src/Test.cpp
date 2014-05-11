#include "Test.h"

Test::Test(QString sen, QString wor) 
	:sentence(sen.split("...")),
	words(wor.split(" ")),
	layout(sen)
{
	sentence_in_use.append(sentence[0]);
	for (qint32 i = 1; i < sentence.size(); i++)
	{
		sentence_in_use.append(gap);
		sentence_in_use.append(sentence[i]);
	}
	relay();
}

Test::~Test()
{
}

void Test::todebug() const
{
	qDebug() << "SENTENCE";
	for (auto a : sentence)
		qDebug() << a;
	qDebug() << "WORDS";
	for (auto a : words)
		qDebug() << a;
}

QRectF Test::boundingRect() const
{
	return layout.boundingRect();
}

void Test::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	layout.draw(painter, QPoint(0, 0));
}

void Test::relay()
{
	layout.setText(sentence_in_use.join(""));
	int leading = 2;
	qreal height = 0;
	layout.setCacheEnabled(true);
	layout.beginLayout();
	while (1) {
		QTextLine line = layout.createLine();
		if (!line.isValid())
			break;

		line.setLineWidth(130);
		height += leading;
		line.setPosition(QPointF(0, height));
		height += line.height();
	}
	layout.endLayout();
}

QStringList Test::getWords()
{
	return words;
}

