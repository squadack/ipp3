#include "DragAndDropView.h"

int DragAndDropView::dragged = -1;
bool DragAndDropView::draggedinfo = false;

DragAndDropView::DragAndDropView(): QGraphicsView()
{
	drop = false;
	
// 	scene()->addWidget(&draglabel);
// 	draglabel = new DraggableLabel(this);
// 	draglabel->setVisible(false);
}

DragAndDropView::~DragAndDropView()
{
	
}

char interpunction(QString tekst) 
{
	char lastchar = 0;
	if ((tekst.contains("...") && tekst.length() > 3) || !tekst.contains("..."))
	{
		if (tekst.endsWith("."))
			lastchar = '.';
		else if (tekst.endsWith(","))
			lastchar = ',';
		else if (tekst.endsWith("!"))
			lastchar = '!';
		else if (tekst.endsWith("?"))
			lastchar = '?';	
	}
	return lastchar;
}

void DragAndDropView::mousePressEvent(QMouseEvent* event)
{
	qDebug() << "mouse pressed on: " << event->pos();
// 	DraggableLabel *child = static_cast<DraggableLabel*>(childAt(event->pos()));
// 	if (!child)
// 		qDebug() << "NOPE";
// 	else
// 		qDebug() << child->text(); // segfault :(
	if (event->button() == Qt::LeftButton)
	{
		QList<DraggableLabel*> tab = ((GraphicsScene*)scene())->Tab();
		for (int i = 0; i < ((GraphicsScene*)scene())->Size(); i++)
		{
			if (tab[i]->geometry().contains(event->pos()) && tab[i]->isDraggable() && !tab[i]->text().contains("..."))
			{
				event->accept();
				QDrag *drag = new QDrag(this);
				dragged = i;
				qDebug() << "dragged = " << dragged;
				draggedinfo = acceptDrops();
				QString txt = tab[i]->text();
				char lastchar = interpunction(txt);
				if (lastchar != 0)
					txt.remove(txt.length() - 1, txt.length());
				QMimeData *mimeData = new QMimeData;
				mimeData->setText(txt);
				drag->setMimeData(mimeData);
				
// 				draglabel->setText(tab[i]->text());
				
				Qt::DropAction dropAction = drag->exec(Qt::MoveAction);
			}
		}
	}
//     QGraphicsView::mousePressEvent(event);
}

void DragAndDropView::dragEnterEvent(QDragEnterEvent* event)
{
		qDebug() << "Drag entered";

		event->acceptProposedAction();
}

void DragAndDropView::dragMoveEvent(QDragMoveEvent* event)
{
	event->acceptProposedAction();
}

void DragAndDropView::dragAccepted() //wtf?
{
	qDebug() << "MY NAME IS FAULT";
	if (draggedinfo)
	{
		qDebug() << "wziales to z sentence";
// 		char last = interpunction(((GraphicsScene*)scene())->Tab()[dragged]->text());
// 		QString txt = "...";
// 		if (last != 0)
// 			txt += last;
// 		((GraphicsScene*)scene())->Tab()[dragged]->setText(txt);
// 		((GraphicsScene*)scene())->Tab()[dragged]->adjustSize();
	}
	else
	{
		qDebug() << "wziales to z words " << dragged;
		emit disappearB(dragged);
	}
	qDebug() << "SEG FAULT";
}

void DragAndDropView::dropEvent(QDropEvent* event)
{
// 	draglabel->setVisible(false);
	if (acceptDrops())
	{
		QList<DraggableLabel*> tab = ((GraphicsScene*)scene())->Tab();
		for (int i = 0; i < ((GraphicsScene*)scene())->Size(); i++)
		{
			if(tab[i]->geometry().contains(event->pos()) && tab[i]->isDraggable())
			{
				qDebug() << "Dropped DA BASS text: " << event->mimeData()->text();
				QString txt = event->mimeData()->text();
				char lastchar = interpunction(tab[i]->text());
				if (lastchar != 0)
					txt.append(lastchar);
				
				if (i == 0)
					txt[0] = txt[0].toUpper();
				tab[i]->setText(txt);
				tab[i]->adjustSize();
				dragAccepted();
				((GraphicsScene*)scene())->relay();
				event->acceptProposedAction();
				
			}
		}
	}
}

void DragAndDropView::setDrop(bool w)
{
	drop = w;
}

void DragAndDropView::mouseMoveEvent(QMouseEvent* event)
{
// 	qDebug() << "move";
    QGraphicsView::mouseMoveEvent(event);
}
