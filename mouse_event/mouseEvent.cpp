#include"mouseEvent.h"

mouseEvent::mouseEvent()
		   :QMainWindow()
{
	setWindowTitle("Test Mouse Event");

	labelStatus = new QLabel();
	labelStatus->setText("Pos");
	
	labelMousePos = new QLabel();
	labelMousePos->setText("");

	statusBar()->addPermanentWidget(labelStatus);
	statusBar()->addPermanentWidget(labelMousePos);

	this->setMouseTracking(true);

	resize(600, 400);
}

void mouseEvent::mouseMoveEvent(QMouseEvent * e )
{
	labelMousePos->setText( "(" + QString::number( e->x() ) +
							"," + QString::number( e->y() ) + ")" );
}

void mouseEvent::mousePressEvent(QMouseEvent* e)
{
	QString str = QString::number(e->x()) + "," + QString::number(e->y());
	if(e->button() == Qt::LeftButton)
	{
		statusBar()->showMessage("Left Button Pressed: " + str);
	}
	else if(e->button() == Qt::RightButton)
	{
		statusBar()->showMessage("Right Button Pressed: " + str);
	}
	else if(e->button() == Qt::MidButton)
	{
		statusBar()->showMessage("Middle Button Pressed: " + str);
	}
}

void mouseEvent::mouseDoubleClickEvent(QMouseEvent* e)
{
	QString str = QString::number(e->x()) + "," + QString::number(e->y());
	if(e->button() == Qt::LeftButton)
	{
		statusBar()->showMessage("Left Button Double Clicked: " + str);
	}
	else if(e->button() == Qt::RightButton)
	{
		statusBar()->showMessage("Right Button Double Clicked: " + str);
	}
}

void mouseEvent::mouseReleaseEvent(QMouseEvent* e )
{
	QString str = QString::number(e->x()) + "," + QString::number(e->y());
	//"3000"为保持的时间
	statusBar()->showMessage("Released:" + str, 3000);
}

