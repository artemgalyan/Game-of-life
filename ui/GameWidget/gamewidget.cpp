#include "gamewidget.h"
#include "ui_GameWidget.h"
#include <QResizeEvent>

#include <QVBoxLayout>

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent), ui(new Ui::GameWidget) {
  ui->setupUi(this);
  QVBoxLayout* l = new QVBoxLayout;
  gv_ = new QGraphicsView(this);
  this->setContentsMargins(0, 0, 0, 0);
  gv_->setFrameStyle(QFrame::NoFrame);
  gv_->setContentsMargins(0, 0, 0, 0);
  this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
  gv_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  gv_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

GameWidget::~GameWidget() {
  delete ui;
}

void GameWidget::SetScene(QGraphicsScene* gs) {
  gv_->setScene(gs);
}

void GameWidget::resizeEvent(QResizeEvent *event) {
  gv_->resize(this->size());
  QWidget::resizeEvent(event);
}
