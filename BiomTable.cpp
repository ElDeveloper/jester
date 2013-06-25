#include "BiomTable.h"

#include <iostream>
#include <fstream>

#include <QByteArray>
#include <QString>

#include <json/json.h>

namespace Jester {
  BiomTable::BiomTable(const QString& fileName) {
    jsonRoot = NULL;
    jsonRoot = new Json::Value;

    QByteArray ba = fileName.toLocal8Bit();
    std::ifstream inFile(ba.data());

    if (!inFile.is_open()) {
      // TODO raise exception
      std::cerr << "Error: could not open file '" << fileName.toStdString() <<
                   "' for reading. Please check that the file exists and has "
                   "read permissions.\n";
      exit(EXIT_FAILURE);
    }

    Json::Reader reader;
    bool successfulParse = reader.parse(inFile, *jsonRoot);

    if (!successfulParse) {
      // TODO raise exception
      std::cerr <<
          "Error: could not parse JSON in file '" << fileName.toStdString() <<
          "'. Please check that the file is in valid JSON format.\n";
      exit(EXIT_FAILURE);
    }

    inFile.close();

    std::cout << *jsonRoot << std::endl;
  }

  BiomTable::~BiomTable() {
    delete jsonRoot;
    jsonRoot = NULL;
  }

  int BiomTable::sampleCount() const {
    return (*jsonRoot)["shape"][1].asInt();
  }

  int BiomTable::observationCount() const {
    return (*jsonRoot)["shape"][0].asInt();
  }

  double BiomTable::data(int row, int column) const {
    if (validIndex(row, column)) {
      return (*jsonRoot)["data"][row][column].asDouble();
    }
    else {
      // TODO raise exception, make better message
      std::cerr << "Error: invalid row or column index.\n";
      exit(EXIT_FAILURE);
    }
  }

  void BiomTable::setData(int row, int column, double value) {
    if (validIndex(row, column)) {
      (*jsonRoot)["data"][row][column] = value;
    }
    else {
      // TODO raise exception, make better message, remove duplicate code
      std::cerr << "Error: invalid row or column index.\n";
      exit(EXIT_FAILURE);
    }
  }

  bool BiomTable::validIndex(int row, int column) const {
    bool isValid = false;

    if (row >= 0 && row < observationCount() &&
       (column >= 0 && column < sampleCount())) {
      isValid = true;
    }

    return isValid;
  }
}
