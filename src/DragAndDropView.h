#ifndef DRAGANDDROPVIEW_H
#define DRAGANDDROPVIEW_H

#include <QtWidgets>

#include "DraggableLabel.h"
#include "GraphicsScene.h"

class DragAndDropView : public QGraphicsView {
	Q_OBJECT;
	
	bool drop;
// 	DraggableLabel *draglabel;
// 	DraggableLabel *dragged;
	static int dragged;
	static bool draggedinfo;
	void dragAccepted();
public:
	DragAndDropView();
	~DragAndDropView();
	void setDrop(bool w);
protected:
	void mousePressEvent(QMouseEvent *event);
	void dragEnterEvent(QDragEnterEvent *event);
	void dragMoveEvent(QDragMoveEvent *event);
	void dropEvent(QDropEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
signals:
	void disappearB(int idx);
};


#endif