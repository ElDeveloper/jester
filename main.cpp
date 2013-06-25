#include <iostream>

#include <QApplication>
#include <QItemDelegate>
#include <QTableView>

#include <json/json.h>

#include "BiomTable.h"
#include "BiomTableModel.h"
#include "JesterMainWindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QString str = "examples/minimal_dense.biom";
  BiomTable table(str);
  std::cout << table.observationCount() << std::endl;
  std::cout << table.sampleCount() << std::endl;

  // Create a model which adapts the BIOM table to the view.
  BiomTableModel model(&table);

  QTableView* view = new QTableView;
  view->setModel(&model);

  //QItemDelegate delegate;
  //view->setItemDelegate(&delegate);

  JesterMainWindow window;
  window.setCentralWidget(view);
  window.show();

  return app.exec();
}
