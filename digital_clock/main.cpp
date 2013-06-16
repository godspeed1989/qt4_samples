#include<QApplication>
#include"digitalclock.h"

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);

	digitalclock clock;
	clock.show();

	return app.exec();
}
