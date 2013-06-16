#include"shapewidget.h"

shapewidget::shapewidget(QWidget* parent):QWidget(parent,Qt::FramelessWindowHint)
{
	QPixmap pix;

	pix.load("tux.png", 0,
			 Qt::AvoidDither |
			 Qt::ThresholdDither |
			 Qt::ThresholdAlphaDither);

	this->resize(pix.size());
	this->setMask(pix.mask());
	this->setWindowOpacity(0.6);
}

void shapewidget::mousePressEvent(QMouseEvent * event)
{
	if(event->button() == Qt::LeftButton)
	{
		dragPosition = event->globalPos() - frameGeometry().topLeft();
		event->accept();
	}
	if(event->button() == Qt::RightButton)
	{
		close();
	}
}

void shapewidget::mouseMoveEvent(QMouseEvent* event)
{
	if(event->buttons() & Qt::LeftButton)
	{
		this->move(event->globalPos() - dragPosition);
		event->accept();
	}
}

void shapewidget::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	painter.drawPixmap( 0 , 0 , QPixmap("tux.png") );
}

