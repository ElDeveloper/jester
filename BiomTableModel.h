#include <QAbstractTableModel>

class QModelIndex;
class QVariant;

class BiomTableModel : public QAbstractTableModel {
  public:
    BiomTableModel(int numRows, int numColumns, double* data);
    virtual ~BiomTableModel();

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

  private:
    int numRows;
    int numColumns;
    double* biomTable;
};
