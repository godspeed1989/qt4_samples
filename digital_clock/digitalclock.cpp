#include"digitalclock.h"

digitalclock::digitalclock(QWidget* parent)
				:QLCDNumber(parent)
{
	QPalette p = palette();		//调色板
	p.setColor(QPalette::Window,Qt::blue);
	QWidget::setPalette(p);

	setWindowFlags(Qt::FramelessWindowHint   //无框架
				  |Qt::WindowStaysOnTopHint);//最前端

	setWindowOpacity(0.3);			//窗口透明度

	QTimer *timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()), this,SLOT(showTime()) );
	timer->start(500);

	resize(150,60);
	showColon = true;		//Colon="冒号"
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

