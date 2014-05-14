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
	wyliczgapy();
	relay();
}

Test::~Test()
{
}

void Test::wyliczgapy()
{
	qDebug() << "KURWAWAWAWAWA";
	gapy.clear();
	int pom = 0;
	for (int i = 0; i < sentence_in_use.size(); i++)
	{
		qDebug() << "WOLOLO";
		if (i % 2 != 0)
		{
			gapy.push_back(pom);
		}
		pom += sentence_in_use[i].size();
	}
}

QPoint Test::wheregapbegins(int a)
{
	QTextLine line = layout.lineForTextPosition(a);
	qreal gapX = line.cursorToX(a);
	qreal gapY = line.y();
	return QPoint(gapX, gapY);
}

int Test::isWithinGap(QPoint p)
{
	int result = -1;
	int i = 1;
	qDebug() << "ISWITHINGAP " << gapy.size();
	for (int a : gapy)
	{
		qDebug() << "ISWITHINGAP_A " << a;
		QPoint point = wheregapbegins(a);
		int length = sentence_in_use[i].size();
		int endx = wheregapbegins(a + length).x();
		QFont fon = layout.font();
		QFontMetrics fmetr(fon);
		if (point.x() <= p.x() && p.x() <= endx && point.y() <= p.y() && p.y() <= point.y() + fmetr.height())
		{
			result = i;
		}
		
		i += 2;
	}
	return result;
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
		line.setPosition(QPoint(0, height));
		height += line.height();
	}
	layout.endLayout();
}

QStringList Test::getWords()
{
	return words;
}

void Test::considerdrop(QPoint pkt)
{
	qDebug() << "CONSIDERING DROP...";
	lastidx = isWithinGap(pkt);
	qDebug() << "IDX: " << lastidx;
	if (lastidx != -1)
	{
		emit gimmeString();
	}
}

void Test::setgap(QString text)
{
	sentence_in_use[lastidx] = text; //STRINGZDROPA;
	emit dropaccepted();
	wyliczgapy();
	relay();
	update();
}

