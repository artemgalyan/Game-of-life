#ifndef GAMEOFLIFE_CONTROLLER_GRIDCONTROLLER_H_
#define GAMEOFLIFE_CONTROLLER_GRIDCONTROLLER_H_

#include "../logic/Grid.h"
#include "../ui/field/gamefield.h"
#include "../Settings/Settings.h"

#include <QVector>
#include <QGraphicsRectItem>

class GridController {
 public:
  explicit GridController(Grid* grid, GameField* game_field);
  void Update();
  void DrawField();
 private:
  Grid* grid_;
  GameField* game_field_;
  QVector<QVector<QGraphicsRectItem*>> cells_;
};

#endif //GAMEOFLIFE_CONTROLLER_GRIDCONTROLLER_H_
