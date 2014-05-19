#include "Test.h"

Test::Test(QString sen, QString wor) 
	:sentence(sen.split("|...|")),
	words(wor.split(" "))
{
	sentence_in_use.append(sentence[0]);
	for (qint32 i = 1; i < sentence.size(); i++)
	{
		sentence_in_use.append(gap);
		sentence_in_use.append(sentence[i]);
	}
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

QStringList Test::getWords() const
{
	return words;
}

QStringList Test::getSplitSentence() const
{
	QStringList temp = sentence_in_use.join("").split(" ");
	return temp;
}


int Test::length() const
{
	QStringList temp = sentence_in_use.join("").split(" ");
	qDebug() << temp.size();
	return temp.size();
	
}
