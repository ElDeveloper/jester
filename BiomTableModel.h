#include <QAbstractTableModel>

class QModelIndex;
class QVariant;

// Used the following as a starting point for this class:
//   http://stackoverflow.com/a/11907059
class BiomTableModel : public QAbstractTableModel {
    Q_OBJECT

  public:
    BiomTableModel(int numRows, int numColumns, double* data);
    virtual ~BiomTableModel();

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;

    Qt::ItemFlags flags(const QModelIndex& index) const;

    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex& index, const QVariant& value,
                 int role = Qt::EditRole);

  private:
    int convertIndex(const QModelIndex& index) const;

  private:
    int numRows;
    int numColumns;
    double* biomTable;
};
