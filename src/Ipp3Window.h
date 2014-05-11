#ifndef IPP3WINDOW_H
#define IPP3WINDOW_H

#include "Test.h"
#include <QtWidgets>

class Ipp3Window : public QMainWindow
{
	Q_OBJECT;
	
	QList<Test*> tests;
	int current_test;
	QGraphicsScene *sceneA;
	QListView *lview;
    QStringListModel *smodl;
    QGraphicsView *viewA;
	QPushButton *buttonz[3];
	
	void loadTests();
public:
    Ipp3Window();
    virtual ~Ipp3Window();
public slots:
	void nexttest();
};

#endif
