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

  //QString str = "examples/10000x10000x0.100_bench.biom";
  //QString str = "examples/minimal_dense.biom";
  QString str = "examples/minimal_sparse.biom";
  Jester::BiomTable table(str);
  std::cout << table.observationCount() << std::endl;
  std::cout << table.sampleCount() << std::endl;

  // Create a model which adapts the BIOM table to the view.
  Jester::BiomTableModel model(&table);

  QTableView* view = new QTableView;
  view->setModel(&model);

  //QItemDelegate delegate;
  //view->setItemDelegate(&delegate);

  Jester::JesterMainWindow window;
  window.setCentralWidget(view);
  window.show();

  return app.exec();
}
