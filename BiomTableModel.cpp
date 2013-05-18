#include "BiomTableModel.h"

#include <QModelIndex>
#include <QVariant>

BiomTableModel::BiomTableModel(int numRows, int numColumns, double* data)
  : numRows(numRows),
    numColumns(numColumns),
    biomTable(data) {
}

BiomTableModel::~BiomTableModel() {
}

int BiomTableModel::rowCount(const QModelIndex& parent) const {
  return numRows;
}

int BiomTableModel::columnCount(const QModelIndex& parent) const {
  return numColumns;
}

Qt::ItemFlags BiomTableModel::flags(const QModelIndex& index) const {
  if (!index.isValid())
    return Qt::ItemIsEnabled;

  return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QVariant BiomTableModel::headerData(int section, Qt::Orientation orientation,
                                    int role) const {
  if (role != Qt::DisplayRole)
    return QVariant();

  if (orientation == Qt::Horizontal)
    return QString("Column %1").arg(section + 1);
  else
    return QString("Row %1").arg(section + 1);
}

QVariant BiomTableModel::data(const QModelIndex& index, int role) const {
  if (!index.isValid() || (role != Qt::DisplayRole && role != Qt::EditRole))
    return QVariant();

  return biomTable[convertIndex(index)];
}

bool BiomTableModel::setData(const QModelIndex& index, const QVariant& value,
                             int role) {
  if (index.isValid() && role == Qt::EditRole) {
    biomTable[convertIndex(index)] = value.toDouble();
    emit dataChanged(index, index);
    return true;
  }

  return false;
}

int BiomTableModel::convertIndex(const QModelIndex& index) const {
  return index.row() * numColumns + index.column();
}
