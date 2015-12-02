#include "dialog.h"
#include "bargraph.h"
#include <QVBoxLayout>
#include <QDebug>

#define NUM_BARS 10

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    this->bg = new BarGraph(this);
    bg->setNumBars(NUM_BARS);
    Bars.resize(NUM_BARS);

    this->timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    timer->start(1000);

    layout->addWidget(bg);
    resize(600, 480);
}

Dialog::~Dialog()
{
    delete timer;
}

void Dialog::timeout()
{
    Bar bar;
    for (int i=0; i<NUM_BARS; i++)
    {
        bar.value = (float)rand() / RAND_MAX;
        bar.clipped = rand() & 1;
        Bars[i] = bar;
    }
    bg->updateBars(Bars);
}
