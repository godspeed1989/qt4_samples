#include"Analogclock.h"

Analogclock::Analogclock(QWidget* parent)
				:QWidget(parent)
{
	setWindowFlags(Qt::FramelessWindowHint
				  |Qt::WindowStaysOnTopHint);
	setWindowOpacity(0.5);
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start(500);
	setWindowTitle("Analog Clock");
	resize(200, 200);
}

void Analogclock::paintEvent(QPaintEvent*)
{
	///////////*Hour hand*////////////
	static const QPoint hourHand[3] = {
			QPoint(7, 8),
			QPoint(-7, 8),
			QPoint(0, -40)
	};
	///////////*Minute hand*///////////
	static const QPoint minuteHand[3] = {
			QPoint(7, 8),
			QPoint(-7, 8),
			QPoint(0, -70)
	};
   	///////////*Hand's color*////////////
	QColor hourColor(127, 0, 127);
	QColor minuteColor(0, 127, 127, 191);
	//
	int side = qMin(width(), height());
	QTime time = QTime::currentTime();
	///////////////*Painter*///////////////
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	//After this call, offset is added to points
	painter.translate(width() / 2, height() / 2);
	painter.scale(side / 200.0, side / 200.0);
	painter.setPen(Qt::NoPen);
	painter.setBrush(hourColor);

	painter.save();//Saves the current painter state 
	painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
	painter.drawConvexPolygon(hourHand, 3);
	painter.restore();//pops a saved state off the stack

	painter.setPen(hourColor);
	for (int i = 0; i < 12; ++i)
	{
			painter.drawLine(88, 0, 96, 0);
			painter.rotate(30.0);
	}

	painter.setPen(Qt::NoPen);
	painter.setBrush(minuteColor);
	painter.save();
	painter.rotate(6.0* ( time.minute() + time.second()/60.0 ) );
	painter.drawConvexPolygon(minuteHand, 3);
	painter.restore();

	painter.setPen(minuteColor);
	for (int j = 0; j < 60; ++j)
	{
		  if ((j % 5) != 0)
					painter.drawLine(92, 0, 96, 0);
		  painter.rotate(6.0);
	}
}

void Analogclock::mousePressEvent(QMouseEvent * e)
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

void Analogclock::mouseMoveEvent(QMouseEvent * e)
{
	if(e->buttons() & Qt::LeftButton)
	{
		move(e->globalPos() - dragPosition);
		e->accept();
	}
}

