#include<QApplication>
#include<QTabWidget>
#include<QPushButton>
#include<QVBoxLayout>
#include<QDialog>

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);

	QDialog* dialog = new QDialog;
	QPushButton* button = new QPushButton("&Button",dialog);
	QObject::connect(button,SIGNAL(clicked()),dialog,SLOT(close()));

	QTabWidget* tab = new QTabWidget(dialog);
	QWidget* w1 = new QWidget;
	QWidget* w2 = new QWidget;
	
	tab->addTab(w1, "&First");
	tab->addTab(w2, "&Second");

	QVBoxLayout* layout = new QVBoxLayout(dialog);
	layout->addWidget(tab);
	layout->addWidget(button);
	dialog->show();

	return app.exec();
}

