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

  // Create a matrix. Taken from http://stackoverflow.com/a/11907059
  const int numRows = 500;
  const int numColumns = 500;
  double matrix[numRows][numColumns];
  for (int i = 0; i < numRows; ++i)
    for (int j = 0; j < numColumns; ++j)
      matrix[i][j] = (i + 1) * (j + 1);

  // Create a model which adapts the data (the matrix) to the view.
  BiomTableModel model(numRows, numColumns, (double*)matrix);

  QTableView* view = new QTableView;
  view->setModel(&model);

  //QItemDelegate delegate;
  //view->setItemDelegate(&delegate);

  JesterMainWindow window;
  window.setCentralWidget(view);
  window.show();

  QString str = "examples/minimal_dense.biom";
  BiomTable table(str);

  return app.exec();
}
