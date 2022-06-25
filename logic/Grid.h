#ifndef GAMEOFLIFE_LOGIC_GRID_H_
#define GAMEOFLIFE_LOGIC_GRID_H_

#include <QVector>

#include "FieldSnapshot/FieldSnapshot.h"
#include "cell/cell.h"

class Grid {
 public:
  struct Index {
    int i;
    int j;
  };
  unsigned int Height() const;
  unsigned int Width() const;
  explicit Grid(const FieldSnapshot& snapshot);
  QVector<Index> Update();
  [[nodiscard]] Cell At(Index index) const;
  [[nodiscard]] Cell At(int i, int j) const;
 private:
  [[nodiscard]] unsigned int NumberOfAliveNeighbours(int i, int j, const QVector<QVector<Cell>>& field) const;
  [[nodiscard]] bool IsCorrectIndex(int i, int j) const;
  QVector<QVector<Cell>> field_;
  unsigned int height_;
  unsigned int width_;
};

#endif //GAMEOFLIFE_LOGIC_GRID_H_
