#include "Ipp3Window.h"


#include <QtWidgets>

void Ipp3Window::loadTests()
{
// 	json magic happens here
	QFile file("../src/testy.json");
	file.open(QIODevice::ReadOnly);
	QByteArray barray = file.readAll();
	QJsonDocument jdocument;
	jdocument = QJsonDocument::fromJson(barray);
	if (jdocument.isEmpty())
		qDebug() << "JSON DOCUMENT EMPTY!";
	
	QJsonArray jarray = jdocument.array();
	qDebug() << "W Dżejsonie jest " << jarray.size() << " objectów";
	
	QJsonObject json;
	for (QJsonArray::const_iterator e = jarray.constBegin(); e != jarray.constEnd(); e++)
	{
		json = (*e).toObject();
		tests.push_back(new Test(json["text"].toString(), json["words"].toString()));
	}
	
	
	if (tests.empty())
	{
		qDebug() << "Failed to load any tests. Loading example...";
		tests.push_back(new Test("Yo momma so ... that she cant even pay attention.", "poor black phat"));
	}
	else
	{
		qDebug() << "Successfully loaded tests.";
	}
	
	//DEBUG
	for (auto a : tests)
	{
		a->todebug();
	}
}

Ipp3Window::Ipp3Window()
	:QMainWindow(nullptr)
{
	setFixedSize(800, 600);
	corr = all = 0;
	locked = true;
	drag.setVisible(false);
	current_test = -1;
	loadTests();
	QWidget *central = new QWidget(this);
    setCentralWidget(central);
	QHBoxLayout *layout = new QHBoxLayout();
	QVBoxLayout *viewLayout = new QVBoxLayout();
	
// 	gbox = new QGroupBox();
	
	viewA = new DragAndDropView();
	viewA->setAcceptDrops(true);
	viewA->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	viewB = new DragAndDropView();
	viewB->setAcceptDrops(false);
	viewB->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	sceneA = new GraphicsScene();
	sceneB = new GraphicsScene();
	
	viewA->setScene(sceneA);
	viewB->setScene(sceneB);
	viewLayout->addWidget(viewA);
// 	viewLayout->addWidget(gbox);
	viewLayout->addWidget(viewB);
	layout->addLayout(viewLayout);
	
	
	nexttest();
	
	
	
	QVBoxLayout *buttonLayout = new QVBoxLayout();
	for (int i = 0; i < 2; i++)
	{
		buttonz[i] = new QPushButton();
		buttonLayout->addWidget(buttonz[i]);
	}
	buttonz[0]->setText("&Check");
	buttonz[1]->setText("&Next");
	connect(buttonz[1], SIGNAL(clicked()), this, SLOT(nexttest()));
	connect(buttonz[0], SIGNAL(clicked()), this, SLOT(check()));
	correctcount.setText("Poprawnie:\n" + QString::number(corr) + " z " + QString::number(all));
	buttonLayout->addWidget(&correctcount);
	
	layout->addLayout(buttonLayout);
	
	central->setLayout(layout);
	
    QAction* a = new QAction(this);
    a->setText( "Quit" );
	a->setShortcut(QKeySequence("Ctrl+Shift+Z"));
    connect(a, SIGNAL(triggered()), SLOT(close()) );
    menuBar()->addMenu( "&File" )->addAction( a );
}

Ipp3Window::~Ipp3Window()
{

}

QStringList mix(const QStringList list) {
	QStringList temp(list), result;
	int x;
	for (int i = 0; i < list.length(); i++)
	{
		x = qrand() % temp.length();
		result.append(temp[x]);
		temp.removeAt(x);
	}
	return result;
}

void Ipp3Window::nexttest()
{
	if (!locked)
		check();
	if (++current_test < tests.count())
	{
		delete sceneA;
		sceneA = new GraphicsScene(tests[current_test]);
		viewA->setScene(sceneA);
		delete sceneB;
		sceneB = new GraphicsScene(mix(tests[current_test]->getWords()));
		viewB->setScene(sceneB);
		connect(viewA, SIGNAL(disappearB(int)), sceneB, SLOT(hide(int)));
		
	}
	else
	{
		delete sceneA;
		sceneA = new GraphicsScene();
		viewA->setScene(sceneA);
		delete sceneB;
		sceneB = new GraphicsScene();
		viewB->setScene(sceneB);
		sceneA->addText("KONIEC");
		buttonz[0]->setVisible(false);
		buttonz[1]->setText("&Close");
		connect(buttonz[1], SIGNAL(clicked()), qApp, SLOT(quit()));
	}
	locked = false;
}

void Ipp3Window::check()
{
	if (!locked)
	{
		for (auto a : sceneA->Tab())
		{
			if (a->isDraggable())
			{
				all++;
				if (a->isCorrect())
					corr++;
			}
		}
		correctcount.setText("Poprawnie:\n" + QString::number(corr) + " z " + QString::number(all));
		qDebug() << "testutestu";
		for (auto a : sceneA->Tab())
			a->setDraggable(false);
		for (auto a : sceneB->Tab())
			a->setDraggable(false);
		locked = true;
	}
}



