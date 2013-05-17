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

QVariant BiomTableModel::data(const QModelIndex& index, int role) const {
  if (!index.isValid() || role != Qt::DisplayRole)
      return QVariant();

  return biomTable[index.row() * numColumns + index.column()];
}
