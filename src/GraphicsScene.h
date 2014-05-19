#pragma once

#include <QtWidgets>
#include "DraggableLabel.h"
#include "Test.h"

class GraphicsScene : public QGraphicsScene {
	Q_OBJECT;
	
	QList<DraggableLabel*> tab;
	int size;
	static const int spacing = 15;
public:
	GraphicsScene(int s = 1);
    GraphicsScene(QStringList t);
    GraphicsScene(Test *t);
	~GraphicsScene();
	
	void relay();
	void refresh(int idx = 0); //
	QList<DraggableLabel*> Tab();
	int Size();
public slots:
	void hide(int idx);
};