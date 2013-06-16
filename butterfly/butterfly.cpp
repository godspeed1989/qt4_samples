#include"butterfly.h"
#include<QtGui>
#include<math.h>
static const double PI = 3.14159;

butterfly::butterfly()
{
	pix_up.load("butterfly1.png");
	pix_down.load("butterfly2.png");
	up = true;
	startTimer(100);
}

QRectF butterfly::boundingRect() const
{
	qreal adjust = 2;
	return QRectF(
				  -pix_up.width()/2-adjust,
				  -pix_up.height()/2-adjust,
				  pix_up.width()+adjust*2,
				  pix_up.height()+adjust*2
				 );
}

void butterfly::paint(QPainter* painter,
					  const QStyleOptionGraphicsItem*,
					  QWidget*)
{
	if(up)
	{
		painter->drawPixmap(boundingRect().topLeft(), pix_up);
		up = !up;
	}
	else
	{
		painter->drawPixmap(boundingRect().topLeft(),pix_down);
		up = !up;
	}
}

void butterfly::timerEvent(QTimerEvent * )
{
	qreal edgex = scene()->sceneRect().right()+boundingRect().width()/2;
	qreal edgetop = scene()->sceneRect().top()+boundingRect().height()/2;
	qreal edgebottom = scene()->sceneRect().bottom()+boundingRect().height()/2;
	if(pos().x() >= edgex)
		setPos(scene()->sceneRect().left(),pos().y());
	if(pos().y() <= edgetop)
		setPos(pos().x(),scene()->sceneRect().bottom());
	if(pos().y() >= edgebottom)
		setPos(pos().x(),scene()->sceneRect().top());

	angle += (qrand()%10)/20.0;
	qreal dx = fabs(sin(angle*PI)*10.0);  
	qreal dy = (qrand()%20)-10.0;   
	   
	setPos(mapToParent(dx,dy));
}
