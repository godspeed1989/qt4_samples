#include <QtNetwork>
#include <QtGui>

class MyNetworkAccessManager : public QNetworkAccessManager
{
	Q_OBJECT
public:
	MyNetworkAccessManager()
	{
		m_pBuffer = new QByteArray();
		QUrl url = QUrl("http://www.baidu.com/img/bdlogo.gif");
		QNetworkRequest req(url);
		
		reply = get(req);
		
		connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadData()));
		connect(reply, SIGNAL(finished()), this, SLOT(slotFinished()));		
	}
	~MyNetworkAccessManager()
	{
		delete m_pBuffer;
		delete reply;
	}

private slots:
	void slotFinished()
	{
		QFile file("bdlogo.gif");
		if(file.open(QIODevice::WriteOnly))
		{
			file.write(*m_pBuffer);
			file.close();			
			QMessageBox::information(NULL, "Hello!", "File has been saved!");			
		} 
		else
		{
			QMessageBox::critical(NULL, "Hello!", "Error saving file!");
		}
	}

	void slotReadData()
	{
		//append data to QByteArray buffer
		*m_pBuffer += reply->readAll();
	}

private:
	QByteArray* m_pBuffer;
	QNetworkReply* reply; 
};

