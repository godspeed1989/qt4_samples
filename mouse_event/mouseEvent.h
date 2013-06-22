#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H
#include<QtGui>
class mouseEvent : public QMainWindow
{
	Q_OBJECT
public:
	mouseEvent();
private:
	QLabel* labelStatus;
	QLabel* labelMousePos;
	QLabel* labelInfo;
protected:
	void mouseMoveEvent(QMouseEvent * );
	void mousePressEvent(QMouseEvent * );
	void mouseReleaseEvent(QMouseEvent * );
	void mouseDoubleClickEvent(QMouseEvent * );
};
#endif

