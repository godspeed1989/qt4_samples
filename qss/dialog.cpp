#include "dialog.h"
#include <QPushButton>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
	QPushButton* button = new QPushButton(this);
	button->setText("sddddd");
}

Dialog::~Dialog()
{
}

