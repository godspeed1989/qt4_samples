#ifndef GROUPBOX_H
#define GROUPBOX_H
#include <QtGui>

class GroupBox : public QToolBox
{
	Q_OBJECT
 public:
	GroupBox(QWidget* parent=0, Qt::WindowFlags f=0);
	QToolButton *toolButton1_1;
	QToolButton *toolButton1_2;
	QToolButton *toolButton2_1;
	QToolButton *toolButton3_1;
};
#endif

