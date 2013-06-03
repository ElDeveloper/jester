#include "BiomTable.h"

#include <iostream>
#include <fstream>

#include <QByteArray>
#include <QString>

#include <json/json.h>

BiomTable::BiomTable(const QString& fileName) {
  jsonRoot = NULL;
  jsonRoot = new Json::Value;

  QByteArray ba = fileName.toLocal8Bit();
  std::ifstream inFile(ba.data());

  if (!inFile.is_open()) {
    // TODO fix me
    std::cout << "bleh\n";
    return;
  }

  Json::Reader reader;
  bool successfulParse = reader.parse(inFile, *jsonRoot);

  if (!successfulParse) {
    // TODO fix me
    std::cout << "blah\n";
    return;
  }

  inFile.close();

  std::cout << *jsonRoot << std::endl;
}

BiomTable::~BiomTable() {
  delete jsonRoot;
  jsonRoot = NULL;
}
