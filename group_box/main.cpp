#include <QApplication>
#include "groupbox.h"

int main(int argc, char* argv[])
{
	QApplication app(argc,argv);
	
	GroupBox* box=new GroupBox();
	box->show();
	box->resize(200, 360);
	return app.exec();
}

