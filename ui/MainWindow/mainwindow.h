#ifndef GAMEOFLIFE_UI_MAINWINDOW_MAINWINDOW_H_
#define GAMEOFLIFE_UI_MAINWINDOW_MAINWINDOW_H_

#include <QWidget>
#include <QPushButton>

#include "../../Game/Game.h"
#include "../GameWidget/gamewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
 Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;

 private:
  Ui::MainWindow *ui;
  Game* background_game_;
  GameWidget* background_game_widget_;
  QPushButton* start_game_;
 protected:
  void resizeEvent(QResizeEvent *event) override;
};

#endif //GAMEOFLIFE_UI_MAINWINDOW_MAINWINDOW_H_
