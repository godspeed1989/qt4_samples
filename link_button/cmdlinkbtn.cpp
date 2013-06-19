#include <QtGui>

class myMainWindow:public QMainWindow
{
public:
	myMainWindow() : QMainWindow()
	{ 
		QVBoxLayout* layout = new QVBoxLayout();
		QWidget* centralWidget = new QWidget();

		QCommandLinkButton* button1 = new QCommandLinkButton(this);
		QCommandLinkButton* button2 = new QCommandLinkButton(this);
		QCommandLinkButton* button3 = new QCommandLinkButton(this);
		QCommandLinkButton* button4 = new QCommandLinkButton(this);

		button1->setText("Button 1");
		button2->setText("Button 2");
		button3->setText("Button 3");
		button4->setText("Button 4");

		layout->addWidget(button1);
		layout->addWidget(button2);
		layout->addWidget(button3);
		layout->addWidget(button4);

		setCentralWidget(centralWidget);
		centralWidget->setLayout(layout);
		setWindowTitle("QCommandLinkButton Example");
		resize(250, 220);
	}
};

int main(int argc,char** argv)
{
	QApplication app(argc,argv);
	myMainWindow* window = new myMainWindow();
	window->show();  
	return app.exec();
}

