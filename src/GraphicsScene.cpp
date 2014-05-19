#include "GraphicsScene.h"


GraphicsScene::GraphicsScene(int s): QGraphicsScene(), size(s)
{
	
}



GraphicsScene::GraphicsScene(QStringList t): QGraphicsScene()
{
	size = t.size();
	QStringList list = t;
// 	tab = new DraggableLabel*[size];
	for (int i = 0; i < size; i++)
	{
		DraggableLabel *label = new DraggableLabel();
		label->setText(list[i]);
		label->setDraggable(true);
		tab.append(label);
// 		tab[i].setText("yomoma");
		addWidget(label);
	}
	relay();
}

GraphicsScene::GraphicsScene(Test* t): QGraphicsScene()
{
	//COPYPASTA!!!!
	size = t->length();
	QStringList list = t->getSplitSentence();
	QStringList words = t->getWords();
	for (int i = 0, gapnr = 0; i < size; i++)
	{
		DraggableLabel *label = new DraggableLabel();
		label->setText(list[i]);
		if (label->text().contains("..."))
		{
			label->setDraggable(true);
			label->setCorrect(words[gapnr++]);
		}
		tab.append(label);
// 		tab[i].setText("yomoma");
		addWidget(label);
	}
	relay();
}


GraphicsScene::~GraphicsScene()
{
	for (auto a : tab)
		delete a;
}

void GraphicsScene::refresh(int idx)
{
	//TODO
}

void GraphicsScene::relay()
{
	qDebug() << "relayed; size: " << size;
	QPoint position = QPoint(0, 0);
	for (int i = 0; i < size; i++)
	{
		qDebug() << "correct/real: " << tab[i]->correct_value << "//" << tab[i]->text();
		QFontMetrics font_metrics = QFontMetrics(tab[i]->Font());
		qDebug() << "ałan tu fru sru " << tab[i]->text();
		if (position.x() + tab[i]->width() > 660)
		{
			position.setX(0);
			position.setY(position.y() + font_metrics.height());
		}
		tab[i]->move(position);
		position.setX(position.x() + tab[i]->width() + spacing);
	}
	qDebug() << "relayed; wololo";
}
QList<DraggableLabel*> GraphicsScene::Tab()
{
	return tab;
}

int GraphicsScene::Size()
{
	return size;
}

void GraphicsScene::hide(int idx)
{
	tab[idx]->setVisible(false);
	tab[idx]->setDraggable(false);
}

