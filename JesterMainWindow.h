#ifndef JESTERMAINWINDOW_H
#define JESTERMAINWINDOW_H

#include <QMainWindow>

namespace Jester {
  class JesterMainWindow : public QMainWindow {
      Q_OBJECT

    public:
      JesterMainWindow(QWidget* parent = 0);
      ~JesterMainWindow();
  };
}

#endif
