#include <QtGui>
// Qt 5 only!!!
void createPDF(QString a_strFileName)
{
	QPdfWriter writer(a_strFileName);	
	writer.setPageSize(QPagedPaintDevice::A4);

	QPainter painter(&writer);

	painter.drawPixmap( QRect(0, 0, writer.logicalDpiX()*8.3, writer.logicalDpiY()*11.7),
						QPixmap("1.png") );

	painter.setPen(Qt::red);
	painter.drawText(0,0,"THIS IS MY RED PDF TEXT..");

	painter.setPen(Qt::green);
	painter.drawText(0,500,"THIS IS MY GREEN PDF TEXT..");

	painter.setPen(Qt::blue);
	painter.drawText(0,1000,"THIS IS MY BLUE PDF TEXT..");

	painter.end();
	QMessageBox::information(NULL,"Hi!","save to the 1.pdf");
}


int main(int argc,char** argv)
{
	QApplication app(argc,argv);  
	createPDF("1.pdf");  
	return app.exec();
}

