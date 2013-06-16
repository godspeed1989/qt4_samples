#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include<QtGui>

class Analogclock : public QWidget
{
	Q_OBJECT

	public:
		Analogclock(QWidget *parent = 0);
		void mousePressEvent(QMouseEvent *);
		void mouseMoveEvent(QMouseEvent *); 
	protected:
		void paintEvent(QPaintEvent* event);
	private:
		QPoint dragPosition;
};
#endif
