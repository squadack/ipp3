#include "DraggableLabel.h"

DraggableLabel::DraggableLabel(QWidget* parent): QLabel(parent)
{
	draggable = false;
	setFont(font);
	setStyleSheet("QLabel { background-color : white; color : blue; }");
}

// DraggableLabel::DraggableLabel(bool drag, QString correct): QLabel(), draggable(drag), correct_value(correct)
// {
// 	setFont(font);
// 	setStyleSheet("QLabel { background-color : white; color : blue; }");
// // 	setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
// }


DraggableLabel::~DraggableLabel()
{

}

bool DraggableLabel::isDraggable()
{
	return draggable;
}


void DraggableLabel::setDraggable(bool drag)
{
	draggable = drag;
}

void DraggableLabel::setCorrect(QString text)
{
	correct_value = text.toLower();
}

QFont DraggableLabel::Font()
{
	return font;
}

bool DraggableLabel::isCorrect()
{
	QString txt = text().toLower();
	char lastchar = 0;
	if (txt.endsWith("."))
			lastchar = '.';
		else if (txt.endsWith(","))
			lastchar = ',';
		else if (txt.endsWith("!"))
			lastchar = '!';
		else if (txt.endsWith("?"))
			lastchar = '?';
	if (lastchar != 0)
		txt = txt.remove(txt.length() - 1, txt.length());
	if (txt == correct_value)
	{
		setStyleSheet("QLabel { background-color : white; color : green; }");
		return true;
	}
	else
	{
		setStyleSheet("QLabel { background-color : white; color : red; }");
		return false;
	}
}

