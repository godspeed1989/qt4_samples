#include <QApplication>
#include "style.h"

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	style s;
	s.show();
	
	return app.exec();
}

