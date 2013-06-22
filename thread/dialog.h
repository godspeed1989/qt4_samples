#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "thread.h"

class Dialog : public QDialog
{
	Q_OBJECT
public:
	explicit Dialog(QObject *parent = 0);
private:
	Thread* t1;
	Thread* t2;
};

#endif // DIALOG_H

