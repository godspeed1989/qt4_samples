#include "http_down.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);	
	MyNetworkAccessManager manager;    
	return app.exec();
}

