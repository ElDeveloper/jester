#include <json/json-forwards.h>

class QString;

class BiomTable {
  public:
    BiomTable(const QString& fileName);
    virtual ~BiomTable();

    int sampleCount() const;
    int observationCount() const;

    double data(int row, int column) const;
    void setData(int row, int column, double value);

  private:
    bool validIndex(int row, int column) const;

  private:
    Json::Value* jsonRoot;
};
