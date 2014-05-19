#ifndef TEST_H
#define TEST_H

#include <QtWidgets>

class Test {
	
    QStringList sentence;
    QStringList words;
	const QString gap = "...";
	QStringList sentence_in_use;

public:
    Test(QString sen, QString wor);
    ~Test();
	int length() const;
    void todebug() const;
	QStringList getWords() const;
	QStringList getSplitSentence() const;
};

#endif
