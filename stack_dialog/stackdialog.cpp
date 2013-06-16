#include"stackdialog.h"

stackdialog::stackdialog(QWidget* parent,Qt::WindowFlags f)
			:QDialog(parent,f)
{
	setWindowTitle("Stacked Widgets");
	//////////*Á´Ê½ÅÅÁÐ*//////////
	list = new QListWidget(this);
	list->insertItem(0,"Window1");
	list->insertItem(1,"Window2");
	list->insertItem(2,"Window3");

	//////////*²ãµþÅÅÁÐ*//////////
	stack = new QStackedWidget(this);
	label1 = new QLabel("This is Window1 !");
    label2 = new QLabel("This is Window2 !");
    label3 = new QLabel("This is Window3 !");
	stack->addWidget(label1);
	stack->addWidget(label2);
	stack->addWidget(label3);

	QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(5);
    mainLayout->setSpacing(5);

    mainLayout->addWidget(list);
    mainLayout->addWidget(stack, 0, Qt::AlignHCenter);

    mainLayout->setStretchFactor(list,1);
    mainLayout->setStretchFactor(stack,3);

    connect(list, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));
}

