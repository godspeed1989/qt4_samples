#ifndef WIDGET_H
#define WIDGET_H

#include <QVector>
#include <QStringList>
#include <QAbstractTableModel>

class Widget : public QAbstractTableModel
{
	Q_OBJECT

public:
	Widget(QObject *parent = 0);

	void setCities(const QStringList&);

	int rowCount(const QModelIndex &parent) const;
	int columnCount(const QModelIndex &parent) const;

	QVariant data(const QModelIndex &index, int role) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;

	~Widget(){}
private:
	int offsetOf(int row ,int column) const;

	QStringList cities;
	QVector<int> distances;
};

#endif // WIDGET_H
