#include <QApplication>

#include "ui/MainWindow/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow mw;
  mw.showFullScreen();
  return QApplication::exec();
}
