#include <QtWidgets>
#include "GraphicsView.h"

GraphicsView::GraphicsView()
	:QGraphicsView(),
	last_clicked(-1)
{
	setAcceptDrops(true);
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
	qDebug() << "ENTER";
	event->acceptProposedAction();
}

void GraphicsView::dragMoveEvent(QDragMoveEvent* event)
{
	event->acceptProposedAction();
}

void GraphicsView::dropEvent(QDropEvent* event)
{
// 	textBrowser->setPlainText(event->mimeData()->text());
// 	mimeTypeCombo->clear();
// 	mimeTypeCombo->addItems(event->mimeData()->formats());
	qDebug() << "DROPPED " << event->pos() << "\nMIME: " << event->mimeData();
	int gapnr = isWithinGap(event->pos());
	event->acceptProposedAction();
	
	emit dropped(event->pos());
	emit muthafucka();
	QGraphicsView::dropEvent(event);
}

int GraphicsView::isWithinGap(QPoint  p)
{
	return 0;
}

void GraphicsView::recivegapnr(int a)
{
	
}

