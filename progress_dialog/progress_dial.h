#include <QtGui>

class MyProgressDialog : public QProgressDialog
{
	Q_OBJECT
public:
	MyProgressDialog() : QProgressDialog()
	{
		value = 0;
		timer = new QTimer(this);
		timer->start(200);
		connect(timer , SIGNAL(timeout()), this, SLOT(handleTimeOut()));
		connect(this , SIGNAL(canceled()), this, SLOT(cancel()));
	}
	~MyProgressDialog() {}
public slots:
	void handleTimeOut()
	{
		if(value == 101)
		{
			close();
		}
		else
		{
			this->setValue(value);
			value++;
		} 
	}

	//Slot that is called when cancel Button is Clicked
	void cancel()
	{
		close();
	}

public:
	QTimer *timer;
	int value;
};

