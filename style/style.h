#ifndef STYLE_H
#define STYLE_H
#include <QtGui>
class QFrame;

class style:public QDialog
{
	Q_OBJECT
	public:
		explicit style();
		void left();
		void right();
	public slots:
		void slotChangeStyle(QString);
	private:
		QFrame *leftFrame;//���� 
		QFrame *rightFrame;//�ҿ�� 
};
#endif
