#ifndef SHAPEWIDGET_H
#define SHAPEWIDGET_H

#include <QtGui>

class shapewidget:public QWidget
{
	Q_OBJECT
	public:
		shapewidget(QWidget* parent = 0);
	protected:
		void mousePressEvent(QMouseEvent *);
		void mouseMoveEvent(QMouseEvent *);	
		void paintEvent(QPaintEvent *);
	private:
		QPoint dragPosition;
};
#endif

