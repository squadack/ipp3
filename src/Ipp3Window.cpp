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
	current_test = -1;
	loadTests();
	QWidget *central = new QWidget(this);
    setCentralWidget(central);
	QHBoxLayout *layout = new QHBoxLayout();
	QVBoxLayout *viewLayout = new QVBoxLayout();
	viewA = new GraphicsView();
	viewA->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	sceneA = new QGraphicsScene();
	lview = new ListView();
	lview->setDragEnabled(true);
	lview->setDragDropMode(QAbstractItemView::DragOnly);
	connect(viewA, SIGNAL(muthafucka()), lview, SLOT(debugCurrentIndex()));
// 	lview->setFlow(QListView::LeftToRight);
// 	lview->setSelectionMode(QAbstractItemView::NoSelection);
	viewA->setScene(sceneA);
	viewLayout->addWidget(viewA);
	viewLayout->addWidget(lview);
	layout->addLayout(viewLayout);
	
	
	nexttest();
	
	
	
	QVBoxLayout *buttonLayout = new QVBoxLayout();
	for (int i = 0; i < 3; i++)
	{
		buttonz[i] = new QPushButton();
		buttonLayout->addWidget(buttonz[i]);
	}
	buttonz[0]->setText("&Next");
	for (int i = 1; i < 3; i++)
	{
		buttonz[i]->setText("test");
	}
	connect(buttonz[0], SIGNAL(clicked()), this, SLOT(nexttest()));
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
	delete sceneA;
	delete lview;
}

void Ipp3Window::nexttest()
{
	sceneA->clear();
// 	if (smodl != nullptr) //chyba con nieco tu cieknie
// 	{
// 		delete smodl;
// 		smodl = nullptr;
// 	}
// 	disconnect(tests[current_test], SIGNAL(dropaccepted()), lview, SLOT(deleteCurrentRow()));
// 	disconnect(viewA, SIGNAL(dropped(QPoint)), tests[current_test], SLOT(considerdrop(QPoint)));
	if (++current_test < tests.count())
	{
		connect(viewA, SIGNAL(dropped(QPoint)), tests[current_test], SLOT(considerdrop(QPoint)));
		connect(tests[current_test], SIGNAL(dropaccepted()), lview, SLOT(deleteCurrentRow()));
		connect(tests[current_test], SIGNAL(gimmeString()), lview, SLOT(stringRequest()));
		connect(lview, SIGNAL(currentString(QString)), tests[current_test], SLOT(setgap(QString)));
		sceneA->addItem(tests[current_test]);
		smodl = new QStringListModel(tests[current_test]->getWords());
		lview->setModel(smodl);
	}
	else
	{
		sceneA->addText("KONIEC");
// 		buttonz[0]->setText("&Close");
// 		connect(buttonz[0], SIGNAL(clicked()), qApp, SLOT(quit()));
	}
}

