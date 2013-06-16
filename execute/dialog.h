#ifndef DIALOG_H
#define DIALOG_H

#include <QtGui/QDialog>

class QTextEdit;
class QProcess;
class QVBoxLayout;
class QPushButton;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QTextEdit* textedit;
    QProcess* proc;
    QPushButton* button;
    QVBoxLayout* layout;
private slots:
    void go();
    void read();
};

#endif // DIALOG_H
