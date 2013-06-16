#ifndef BUTTERFLY_H
#define BUTTERFLY_H
#include<QGraphicsItem>
#include<QObject>
class butterfly : public QObject, public QGraphicsItem//"item"
{
	Q_OBJECT

	public:
		butterfly();
		void timerEvent(QTimerEvent * );
		QRectF boundingRect() const;//系统自带的visual  
	protected:
				void paint(QPainter* painter,
						   const QStyleOptionGraphicsItem* option,
						   QWidget* widget);
	private:
		bool up;
		QPixmap pix_up;
 		QPixmap pix_down;
		qreal angle;	 
};
#endif
