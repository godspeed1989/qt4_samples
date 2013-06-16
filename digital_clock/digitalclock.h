#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H
#include <QtGui>

class digitalclock:public QLCDNumber
{
	Q_OBJECT
	public:
		digitalclock(QWidget* parent=0);
		// overload the mouse event
		void mousePressEvent(QMouseEvent *);
		void mouseMoveEvent(QMouseEvent *); 
	public slots:
		void showTime();
	private:
		bool showColon;
		QPoint dragPosition;//´¢´æ×ø±ê
};
#endif
