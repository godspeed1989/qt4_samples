#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
class QLabel;

typedef enum
{ English , Chinese }Language;

class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog(QWidget *parent = 0);
    ~Dialog(){}
private:
    Language flag;
    QLabel* label;
    QPushButton* button;

private slots:
    void changeLan();
    void reTranslate();
};

#endif // DIALOG_H
