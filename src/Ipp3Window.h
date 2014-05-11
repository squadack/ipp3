#ifndef IPP3WINDOW_H
#define IPP3WINDOW_H

#include "Test.h"
#include <QtWidgets>

class Ipp3Window : public QMainWindow
{
	Q_OBJECT;
	
	QList<Test*> tests;
	
	void loadTests();
public:
    Ipp3Window();
    virtual ~Ipp3Window();
};

#endif
