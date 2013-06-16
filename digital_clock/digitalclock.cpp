#include"digitalclock.h"

digitalclock::digitalclock(QWidget* parent)
				:QLCDNumber(parent)
{
	QPalette p = palette();		//��ɫ��
	p.setColor(QPalette::Window,Qt::blue);
	QWidget::setPalette(p);

	setWindowFlags(Qt::FramelessWindowHint   //�޿��
				  |Qt::WindowStaysOnTopHint);//��ǰ��

	setWindowOpacity(0.3);			//����͸����

	QTimer *timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()), this,SLOT(showTime()) );
	timer->start(500);

	resize(150,60);
	showColon = true;		//Colon="ð��"
}

void digitalclock::showTime()
{
	QTime time = QTime::currentTime();
	QString text =time.toString("hh:mm");
	if(showColon)
	{
		text[2] = ':';
		showColon = false;
	}
	else
	{
		text[2] = ' ';
		showColon = true;
	}
	display(text);
}

void digitalclock::mousePressEvent(QMouseEvent * e)
{
	if(e->button() == Qt::LeftButton)
	{
		dragPosition = e->globalPos() - frameGeometry().topLeft();
		e->accept();
	}
	if(e->button() == Qt::RightButton)
	{
		close();
	}
}

void digitalclock::mouseMoveEvent(QMouseEvent * e)
{
	if(e->buttons() & Qt::LeftButton)
	{
		move(e->globalPos() - dragPosition);
		e->accept();
	}
}

