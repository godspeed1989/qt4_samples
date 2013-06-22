#include "thread.h"
#include <QDebug>

Thread::Thread(const char* str)
{
	text = QString(str);
	stop = true;
}

void Thread::run()
{
	/*��Ҫ�������� , д������*/
	stop = false;
	while(!stop)
	{
		qDebug() << text;
		this->sleep(1.3);
	}
}

void Thread::hold()
{
	stop = true;
}

