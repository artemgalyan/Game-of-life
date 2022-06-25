#include "gamefield.h"

#include <QApplication>
#include <QScreen>

GameField::GameField(unsigned int numberOfCellsW, unsigned int numberOfCellsH, QObject *parent) :
    QGraphicsScene(parent), numberOfCellsW_(numberOfCellsW), numberOfCellsH_(numberOfCellsH) {
}

GameField::~GameField() = default;
QGraphicsRectItem *GameField::DrawCell(const QPen &pen, const QBrush &b, int i, int j) {
  auto size = QApplication::primaryScreen()->size();
  int cell_width = size.width() / numberOfCellsW_;
  int cell_height = size.height() / numberOfCellsH_;
  return addRect(j * cell_width, i * cell_height, cell_width, cell_height, pen, b);
}
