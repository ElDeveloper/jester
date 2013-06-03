#include <json/json-forwards.h>

class QString;

class BiomTable {
  public:
    BiomTable(const QString& fileName);
    virtual ~BiomTable();

  private:
    Json::Value* jsonRoot;
};
