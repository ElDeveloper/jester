#ifndef BIOMTABLE_H
#define BIOMTABLE_H

#include <json/json-forwards.h>

class QString;

namespace Jester {
  class BiomTable {
    public:
      BiomTable(const QString& fileName);
      virtual ~BiomTable();

      int sampleCount() const;
      int observationCount() const;

      QString sampleId(int index) const;
      QString observationId(int index) const;

      double data(int row, int column) const;
      void setData(int row, int column, double value);

    private:
      bool validIndex(int row, int column) const;

    private:
      Json::Value* jsonRoot;
  };
}

#endif
