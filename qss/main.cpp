#include <QtGui/QApplication>
#include <QFile>
#include "dialog.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QFile file(":/candy.qss");
	file.open(QFile::ReadOnly);
	app.setStyleSheet(file.readAll());

	Dialog w;
	w.show();
	return app.exec();
}

