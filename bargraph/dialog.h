#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include "bargraph.h"

class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QTimer *timer;
    BarGraph *bg;
    QVector<Bar> Bars;
private slots:
    void timeout();
};

#endif // DIALOG_H
