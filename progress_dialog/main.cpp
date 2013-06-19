#include "progress_dial.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	MyProgressDialog * progressDialog = new MyProgressDialog();
	progressDialog->show();

	return app.exec();
}

