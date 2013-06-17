#include <QApplication>
#include <QMainWindow>
#include <QTableWidget>

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	QMainWindow *window = new QMainWindow();

	window->setWindowTitle(QString::fromUtf8("QTableWidget Set Header Title"));
	window->resize(400, 250);

	QTableWidget* table = new QTableWidget();

	//Set table row count 1 and column count 3
	table->setRowCount(1);
	table->setColumnCount(3);

	table->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

	//Set Header Label Texts Here
	table->setHorizontalHeaderLabels(QString("HEADER 1;HEADER 2;HEADER 3").split(";"));	

	//Add Table items here
	table->setItem(0, 0, new QTableWidgetItem("ITEM 1"));
	table->setItem(0, 1, new QTableWidgetItem("ITEM 2"));
	table->setItem(0, 2, new QTableWidgetItem("ITEM 3"));

	window->setCentralWidget(table);	
	window->show();
	return app.exec();
}

