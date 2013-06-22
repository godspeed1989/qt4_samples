#include "thread.h"
#include <QDebug>

Thread::Thread(const char* str)
{
	text = QString(str);
	stop = true;
}

void Thread::run()
{
	/*你要做的事情 , 写在这里*/
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

