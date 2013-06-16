#include <QApplication>
#include <QTableView>
#include <QHeaderView>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList cities;
    cities<<"Xi'an"<<"Beijing"<<"ShangHai"<<"ChongQing"<<"Tokyo"<<"Pairs";

    Widget* widget = new Widget();
    widget->setCities(cities);

    QTableView tableView;
    tableView.setModel(widget);
    tableView.setAlternatingRowColors(true);
    tableView.setWindowTitle("Cities");

    tableView.show();

    return a.exec();
}
