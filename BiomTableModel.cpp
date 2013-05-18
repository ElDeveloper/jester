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

QVariant BiomTableModel::headerData(int section, Qt::Orientation orientation,
                                    int role) const {
   if (role != Qt::DisplayRole)
     return QVariant();

   if (orientation == Qt::Horizontal)
     return QString("Column %1").arg(section);
   else
     return QString("Row %1").arg(section);
}

QVariant BiomTableModel::data(const QModelIndex& index, int role) const {
  if (!index.isValid() || role != Qt::DisplayRole)
      return QVariant();

  return biomTable[index.row() * numColumns + index.column()];
}
