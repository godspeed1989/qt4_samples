#include<QApplication>
#include"Analogclock.h"

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);

	Analogclock* clock = new Analogclock();
	clock->show();

	return app.exec();
}

