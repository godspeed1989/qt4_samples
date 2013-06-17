#include <QtNetwork>
#include <QtGui>
int main(int argc,char** argv)
{
	QApplication app(argc,argv);
	QNetworkInterface* network = new QNetworkInterface();
	QString strNetworkInterfaces;

	foreach(QNetworkInterface interface,network->allInterfaces())
	{
		strNetworkInterfaces = strNetworkInterfaces +
		"\nInterface Name: " +interface.humanReadableName()+
		"\n---------------------------";
		foreach(QHostAddress addr,network->allAddresses())
		{
			strNetworkInterfaces = strNetworkInterfaces +
			"\nAddress Entry : " + addr.toString();
		}

		strNetworkInterfaces  = strNetworkInterfaces +	  
		"\nHardware Address: " +
		interface.hardwareAddress() +
		"\nIs UP:"+(interface.flags().testFlag(QNetworkInterface::IsUp)?"YES":"NO") +
		"\nIs Running:"+(interface.flags().testFlag(QNetworkInterface::IsRunning)?"YES":"NO") +
		"\nCan Broadcast:"+(interface.flags().testFlag(QNetworkInterface::CanBroadcast)?"YES":"NO") +
		"\nIs LoopBack:"+(interface.flags().testFlag(QNetworkInterface::IsLoopBack)?"YES":"NO") +
		"\nIs PointToPoint:"+(interface.flags().testFlag(QNetworkInterface::IsPointToPoint)?"YES":"NO") +
		"\nCan Multicast:"+(interface.flags().testFlag(QNetworkInterface::CanMulticast)?"YES":"NO") +
		"\n";
	}

	QMessageBox::information(NULL, "Network Interfaces..", strNetworkInterfaces);

	return app.exec();
}
