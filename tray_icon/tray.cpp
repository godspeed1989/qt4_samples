#include <QtGui>
#include "tray.h"

tray::tray()
{
	this->createActions();
	this->createTrayIcon();
	this->setIcon();

	this->title = new QLineEdit("Title");
	this->text = new QTextEdit("Text is here");
	this->button = new QPushButton("&Tray Message");
	this->groupbox = new QGroupBox("Tray Setting...");

	connect(button, SIGNAL(clicked()), this, SLOT(showMessage()));

	mainlayout = new QVBoxLayout();
	mainlayout->addWidget(title);
	mainlayout->addWidget(text);
	mainlayout->addWidget(button);
	groupbox->setLayout(mainlayout);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(groupbox);
	this->setLayout(layout); 
	
	trayIcon->show();
}

void tray::createActions()
{
	max = new QAction("Max",this);
	connect(max, SIGNAL(triggered()), this, SLOT(showMaximized()));
	min = new QAction("Min",this);
	connect(min, SIGNAL(triggered()), this, SLOT(hide()) );
	res = new QAction("&Restore",this);
	connect(res, SIGNAL(triggered()), this, SLOT(showNormal()));
	bye = new QAction("&Exit",this);
	connect(bye, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void tray::createTrayIcon()
{
	trayMenu = new QMenu;
	trayMenu->addAction(max);
	trayMenu->addAction(min);
	trayMenu->addAction(res);
	trayMenu->addSeparator();
	trayMenu->addAction(bye);
	
	trayIcon = new QSystemTrayIcon(this);
	trayIcon->setContextMenu(trayMenu);
}

void tray::showMessage()
{
	QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(1);
	trayIcon->showMessage(title->text(), text->toPlainText(), icon, 5 * 1000);
}

void tray::setIcon()
{
	QIcon icon = QIcon("heart.svg");
	trayIcon->setIcon(icon);
	setWindowIcon(icon);
	trayIcon->setToolTip("heart icon");
}

