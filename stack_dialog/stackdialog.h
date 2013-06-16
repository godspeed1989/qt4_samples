#ifndef STACKDIALOG_H
#define STACKDIALOG_H
#include<QtGui>

class stackdialog:public QDialog
{
	Q_OBJECT
public:
	stackdialog(QWidget* parent = 0,Qt::WindowFlags f = 0);
	//Label
	QLabel* label1;
	QLabel* label2;
	QLabel* label3;
	//Widget
	QListWidget* list;
	QStackedWidget* stack;
};
#endif
