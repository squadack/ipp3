#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QtWidgets>

class ListView : public QListView {
	Q_OBJECT;
public:
    ListView(QWidget* parent = 0);
    ~ListView();
public slots:
	void debugCurrentIndex();
	void deleteRow(int x);
	void deleteCurrentRow();
	void stringRequest();
signals:
	void currentString(QString);

};

#endif