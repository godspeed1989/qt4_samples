#include <QCalendarWidget>
#include <QMessageBox>

class MyCalendarWidget: public QCalendarWidget
{
	Q_OBJECT
public:
	MyCalendarWidget()
	{
		connect(this,SIGNAL(clicked(const QDate)),this,SLOT(slotClicked(const QDate)));
	}

	~MyCalendarWidget()
	{}

private slots:
	void slotClicked(const QDate& date)
	{
		QMessageBox::information(NULL,"New Date Selected!",date.toString());
	}
};

