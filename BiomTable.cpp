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

  BiomTable::MatrixType BiomTable::matrixType() const {
    QString matrixTypeString = QString::fromStdString(
        (*jsonRoot)["matrix_type"].asString());

    if (matrixTypeString == "dense") {
      return Dense;
    }
    else if (matrixTypeString == "sparse") {
      return Sparse;
    }
    else {
      // TODO raise exception
      std::cerr <<
          "Error: unrecognized matrix type '" <<
          matrixTypeString.toStdString() << "'.\n";
      exit(EXIT_FAILURE);
    }
  }

  QString BiomTable::sampleId(int index) const {
    if (index >= 0 && index < sampleCount()) {
      return QString::fromStdString(
          (*jsonRoot)["columns"][index]["id"].asString());
    }
    else {
      // TODO raise exception, make better message
      std::cerr << "Error: invalid sample index.\n";
      exit(EXIT_FAILURE);
    }
  }

  QString BiomTable::observationId(int index) const {
    if (index >= 0 && index < observationCount()) {
      return QString::fromStdString(
          (*jsonRoot)["rows"][index]["id"].asString());
    }
    else {
      // TODO raise exception, make better message
      std::cerr << "Error: invalid observation index.\n";
      exit(EXIT_FAILURE);
    }
  }

  double BiomTable::data(int row, int column) const {
    double dataValue = -1.0;

    if (validIndex(row, column)) {
      if (matrixType() == Dense) {
        dataValue = (*jsonRoot)["data"][row][column].asDouble();
      }
      else {
        // Extremely naive and inefficient. Just putting something in place for
        // now...
        bool foundEntry = false;
        for (unsigned int i = 0;
             !foundEntry && i < (*jsonRoot)["data"].size();
             i++) {
          const Json::Value nonZeroEntry = (*jsonRoot)["data"][i];

          if (nonZeroEntry[0].asInt() == row &&
              nonZeroEntry[1].asInt() == column) {
            dataValue = nonZeroEntry[2].asDouble();
            foundEntry = true;
          }
        }

        if (!foundEntry) {
          dataValue = 0.0;
        }
      }
    }
    else {
      // TODO raise exception, make better message
      std::cerr << "Error: invalid row or column index.\n";
      exit(EXIT_FAILURE);
    }

    return dataValue;
  }

  void BiomTable::setData(int row, int column, double value) {
    if (validIndex(row, column)) {
      if (matrixType() == Dense) {
        (*jsonRoot)["data"][row][column] = value;
      }
      else {
        bool foundEntry = false;
        for (unsigned int i = 0;
             !foundEntry && i < (*jsonRoot)["data"].size();
             i++) {
          Json::Value nonZeroEntry = (*jsonRoot)["data"][i];

          if (nonZeroEntry[0].asInt() == row &&
              nonZeroEntry[1].asInt() == column) {
            // TODO fix so that zeros aren't written out
            nonZeroEntry[2] = value;
            (*jsonRoot)["data"][i] = nonZeroEntry;
            foundEntry = true;
          }
        }

        if (!foundEntry) {
          Json::Value newEntry(Json::arrayValue);
          newEntry.resize(3);
          newEntry[0] = row;
          newEntry[1] = column;
          newEntry[2] = value;
          (*jsonRoot)["data"].append(newEntry);
        }
      }
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
