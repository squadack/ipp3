#ifndef IPP3WINDOW_H
#define IPP3WINDOW_H

#include "Test.h"
#include "DragAndDropView.h"
#include "GraphicsScene.h"
#include "DraggableLabel.h"
#include <QtWidgets>

class Ipp3Window : public QMainWindow
{
	Q_OBJECT;
	
	QList<Test*> tests;
	int current_test;
	int corr, all;
	bool locked;
	GraphicsScene *sceneA, *sceneB;
    DragAndDropView *viewA;
    DragAndDropView *viewB;
	QPushButton *buttonz[2];
	QLabel correctcount;
	DraggableLabel drag;
	
	void loadTests();
public:
    Ipp3Window();
    virtual ~Ipp3Window();
public slots:
	void nexttest();
	void check();
};

#endif
