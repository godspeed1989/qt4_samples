#include "calender.h"
#include <QApplication>
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MyCalendarWidget * myCalendarWidget = new MyCalendarWidget();
	myCalendarWidget->show();

	return app.exec();
}

