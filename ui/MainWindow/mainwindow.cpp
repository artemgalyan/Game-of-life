#include "mainwindow.h"
#include "ui_MainWindow.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setContentsMargins(0, 0, 0, 0);
  background_game_widget_ = new GameWidget(this);
  background_game_ = new Game(384, 216, 100);
  background_game_widget_->resize(this->size());
  background_game_widget_->SetScene(background_game_->GetGameField());
  background_game_->DrawField();
  background_game_->Run();
//  start_game_ = new QPushButton("Start game", this);
//  start_game_->setFont(QFont("Arial", 15));
//  start_game_->setStyleSheet("border-radius: 150px; background-color: #D7DBDD;");
//  QVBoxLayout* l = new QVBoxLayout(this);
//  l->setAlignment(Qt::AlignCenter);
//  l->addWidget(start_game_);
//  setLayout(l);
}

MainWindow::~MainWindow() {
  delete ui;
}
void MainWindow::resizeEvent(QResizeEvent *event) {
  background_game_widget_->resize(this->size());
  QWidget::resizeEvent(event);
}
