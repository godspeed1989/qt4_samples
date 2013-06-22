#include "dialog.h"
#include <QPushButton>
#include <QVBoxLayout>

Dialog::Dialog(QObject *)
{
	t1 = new Thread("Thread : 1");
	t2 = new Thread("Thread : 2");

	QPushButton* button1 = new QPushButton( tr("Run Thread1"), this );
	QPushButton* button2 = new QPushButton( tr("Run Thread2"), this );
	QPushButton* button3 = new QPushButton( tr("Stop Thread1"), this );
	QPushButton* button4 = new QPushButton( tr("Stop Thread2"), this );
	QPushButton* btn_exit = new QPushButton( tr("Exit"), this );

	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(button1);
	layout->addWidget(button2);
	layout->addWidget(button3);
	layout->addWidget(button4);
	layout->addWidget(btn_exit);

	connect(button1, SIGNAL(clicked()), t1, SLOT(start()));
	connect(button2, SIGNAL(clicked()), t2, SLOT(start()));
	connect(button3, SIGNAL(clicked()), t1, SLOT(hold()));
	connect(button4, SIGNAL(clicked()), t2, SLOT(hold()));
	connect(btn_exit, SIGNAL(clicked()), this, SLOT(close()));
}


