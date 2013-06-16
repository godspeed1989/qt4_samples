#include <QtGui>
#include <QTranslator>
#include "dialog.h"

Dialog::Dialog(QWidget *parent)
	: QDialog(parent)
{
	//先不要设置 文字
	label = new QLabel(this);
	button = new QPushButton(this);
	connect(button, SIGNAL(clicked()), this, SLOT(changeLan()));
	
	flag = English;
	this->reTranslate();

	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(label);
	layout->addWidget(button);
}

void Dialog::changeLan()
{
	QTranslator translator;
	if(flag == English)
	{
		translator.load("dialog_zh.qm");
		flag = Chinese;
	}
	else
	{
		translator.load("dialog_en.qm");
		flag = English;
	}
	qApp->installTranslator(&translator);
	reTranslate();
}

void Dialog::reTranslate()
{
	label->setText(tr("Label"));
	button->setText(tr("Change"));
	this->setWindowTitle(tr("International..."));
}

