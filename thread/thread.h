#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Thread : public QThread
{
	Q_OBJECT
public:
	Thread(const char*);
private:
	QString text;
	bool stop;
	void run();
public slots:
	void hold();
};

#endif // THREAD_H

