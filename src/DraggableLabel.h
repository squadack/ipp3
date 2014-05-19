#pragma once

#include <QtWidgets>

class DraggableLabel : public QLabel {
	bool draggable;
	const QFont font = QFont("Comic Sans MS", 30);
public:
	QString correct_value;

    DraggableLabel(QWidget* parent = 0);
// 	DraggableLabel(bool drag = 0, QString correct = "");
	~DraggableLabel();
	
	bool isDraggable();
	bool isCorrect();
	void setDraggable(bool drag);
	void setCorrect(QString text);
	QFont Font();
};