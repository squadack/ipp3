#include "ListView.h"

ListView::ListView(QWidget* parent): QListView(parent)
{

}

ListView::~ListView()
{

}

void ListView::debugCurrentIndex()
{
	qDebug() << currentIndex().row();
	
}

void ListView::deleteRow(int x)
{
	model()->removeRow(x);
}

void ListView::deleteCurrentRow()
{
	model()->removeRow(currentIndex().row());
}

void ListView::stringRequest()
{
	emit currentString(currentIndex().data().toString());
}
