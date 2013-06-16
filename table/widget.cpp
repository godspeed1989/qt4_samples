#include "widget.h"

Widget::Widget(QObject *parent) : QAbstractTableModel(parent)
{
}

void Widget::setCities(const QStringList & cityNames)
{
	cities = cityNames;
	int count = cities.count();
	distances.resize( ( count*(count - 1) ) / 2 );
	distances.fill(0);
}

int Widget::rowCount(const QModelIndex &) const
{
	return cities.count();
}

int Widget::columnCount(const QModelIndex &) const
{
	return cities.count();
}

QVariant Widget::data(const QModelIndex &index, int role) const
{
	if(!index.isValid())
		return QVariant();
	if(role == Qt::TextAlignmentRole)
	{
		return int(Qt::AlignRight | Qt::AlignCenter );
	}
	else if (role == Qt::DisplayRole)
	{
		if(index.row() == index.column())
		{
			return 0;
		}
		int offset = offsetOf(index.row() , index.column());
		return distances[offset];
	}
	return QVariant();
}

bool Widget::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if(index.isValid() && index.row() != index.column() && role == Qt::EditRole)
	{
		int offset = offsetOf(index.row(), index.column());
		distances[offset] = value.toInt();

		QModelIndex transposedIndex = createIndex(index.column() , index.row());

		emit dataChanged(index, index);
		emit dataChanged(transposedIndex , transposedIndex);
	}
	return false;
}

QVariant Widget::headerData(int section, Qt::Orientation, int role) const
{
	if(role == Qt::DisplayRole)
	{
		return cities[section];
	}
	else
	{
		return QVariant();
	}
}

Qt::ItemFlags Widget::flags(const QModelIndex &index) const
{
	Qt::ItemFlags flags = QAbstractItemModel::flags(index);
	if(index.row() != index.column())
	{
		flags |= Qt::ItemIsEditable;
	}
	return flags;
}

int Widget::offsetOf(int row, int column) const
{
	if(row < column)
		qSwap(row , column);
	return (row*(row-1) / 2)+column;
}

