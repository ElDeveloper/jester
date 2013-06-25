#include "BiomTableModel.h"

#include <QModelIndex>
#include <QVariant>

#include "BiomTable.h"

BiomTableModel::BiomTableModel(BiomTable* table)
  : table(table) {
}

BiomTableModel::~BiomTableModel() {
  delete table;
  table = NULL;
}

int BiomTableModel::rowCount(const QModelIndex& parent) const {
  return table->observationCount();
}

int BiomTableModel::columnCount(const QModelIndex& parent) const {
  return table->sampleCount();
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

  return table->data(index.row(), index.column());
}

bool BiomTableModel::setData(const QModelIndex& index, const QVariant& value,
                             int role) {
  if (index.isValid() && role == Qt::EditRole) {
    table->setData(index.row(), index.column(), value.toDouble());
    emit dataChanged(index, index);
    return true;
  }

  return false;
}
