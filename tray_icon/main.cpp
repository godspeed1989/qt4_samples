#include<QApplication>
#include<QPushButton>
#include"tray.h"
int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	tray systray;
	systray.show();

	QApplication::setQuitOnLastWindowClosed(false);
	return app.exec();
}
