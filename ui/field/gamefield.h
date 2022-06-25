#ifndef GAMEOFLIFE_UI_FIELD_GAMEFIELD_H_
#define GAMEOFLIFE_UI_FIELD_GAMEFIELD_H_

#include <QGraphicsScene>
#include <QColor>
#include <QBrush>

#include "../../Settings/Settings.h"

class GameField : public QGraphicsScene {
 Q_OBJECT

 public:
  explicit GameField(unsigned int numberOfCellsW, unsigned int numberOfCellsH, QObject *parent = nullptr);
  [[nodiscard]] QGraphicsRectItem *DrawCell(const QPen &pen, const QBrush &b, int i, int j);
  ~GameField() override;
 private:
  unsigned int numberOfCellsW_;
  unsigned int numberOfCellsH_;
};

#endif //GAMEOFLIFE_UI_FIELD_GAMEFIELD_H_
