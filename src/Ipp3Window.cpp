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
	
	for (auto a : tests)
	{
		a->todebug();
	}
}

Ipp3Window::Ipp3Window()
	:QMainWindow(nullptr)
{
	setMinimumSize(800, 600);
	
	QWidget *central = new QWidget(this);
    setCentralWidget(central);
	
	loadTests();
	
	QHBoxLayout *layout = new QHBoxLayout();
	
	QVBoxLayout *viewLayout = new QVBoxLayout();
	QGraphicsView *viewA = new QGraphicsView();
	viewA->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	QGraphicsView *viewB = new QGraphicsView();
	QGraphicsScene *sceneA = new QGraphicsScene();
	//testing
	
	sceneA->addItem(tests[0]);
	
	QGraphicsScene *sceneB = new QGraphicsScene();
////////////////////	
	viewA->setScene(sceneA);
	viewB->setScene(sceneB);
	viewLayout->addWidget(viewA);
// 	viewLayout->addWidget(viewB);
	QStringListModel *smodl = new QStringListModel(tests[0]->getWords());
	QListView *lview = new QListView();
	lview->setModel(smodl);

	viewLayout->addWidget(lview);
	layout->addLayout(viewLayout);
	
	QVBoxLayout *buttonLayout = new QVBoxLayout();
	QPushButton *buttonz[3];
	for (auto a : buttonz)
	{
		a = new QPushButton();
		a->setText("test");
		buttonLayout->addWidget(a);
	}
	layout->addLayout(buttonLayout);
	
	central->setLayout(layout);
	
    QAction* a = new QAction(this);
    a->setText( "Quit" );
	a->setShortcut(QKeySequence("Ctrl+Shift+0"));
    connect(a, SIGNAL(triggered()), SLOT(close()) );
    menuBar()->addMenu( "&File" )->addAction( a );
}

Ipp3Window::~Ipp3Window()
{
	for (auto a : tests)
	{
		delete a;
	}
}


