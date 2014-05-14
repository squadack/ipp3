#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QtWidgets>
#include "Test.h"

class GraphicsView : public QGraphicsView {
	
	Q_OBJECT;
	int last_clicked;
public:
    GraphicsView();
    ~GraphicsView();
	int isWithinGap(QPoint p);
	
public slots:
	void recivegapnr(int a);
protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dragMoveEvent(QDragMoveEvent *event);
	void dropEvent(QDropEvent *event);
	void mousePressEvent(QMouseEvent *event);
signals:
	void muthafucka();
	void dropped(QPoint);
};

#endif
