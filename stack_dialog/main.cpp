#include<QApplication>
#include"stackdialog.h"
int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	stackdialog dialog;
	dialog.show();

	return app.exec();
}