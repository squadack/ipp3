#include <QtWidgets>
#include "GraphicsView.h"

GraphicsView::GraphicsView()
	:QGraphicsView(),
	last_clicked(-1)
{

}

GraphicsView::~GraphicsView()
{

}

void GraphicsView::mousePressEvent(QMouseEvent* event)
{
	
    QGraphicsView::mousePressEvent(event);
}

void GraphicsView::dragEnterEvent(QDragEnterEvent* event)
{
    QGraphicsView::dragEnterEvent(event);
}

void GraphicsView::dragMoveEvent(QDragMoveEvent* event)
{
    QGraphicsView::dragMoveEvent(event);
}

void GraphicsView::dropEvent(QDropEvent* event)
{
    QGraphicsView::dropEvent(event);
}
