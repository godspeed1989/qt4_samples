#include "dialog.h"
#include <QProcess>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    proc = new QProcess(this);

    connect(proc,SIGNAL(readyReadStandardOutput()),this,SLOT(read()));

    textedit = new QTextEdit(this);
    textedit->setReadOnly(true);
    textedit->setBackgroundRole(QPalette::Window);

    button = new QPushButton(tr("&Start"));
    connect(button,SIGNAL(clicked()),this,SLOT(go()));

    layout = new QVBoxLayout(this);
    layout->addWidget(textedit);
    layout->addWidget(button);

    resize(400,200);
}

Dialog::~Dialog()
{}

void Dialog::go()
{
    QStringList list("-l");
    list.append("-a");
    proc->start(QString("ls"),list);
}

void Dialog::read()
{
    QByteArray bytearr = proc->readAllStandardOutput();
    textedit->append( QString(bytearr.data()) );
}

