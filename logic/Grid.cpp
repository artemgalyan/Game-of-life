#include "Grid.h"

Grid::Grid(const FieldSnapshot &snapshot) {
  width_ = snapshot.Width();
  height_ = snapshot.Height();
  for (int i = 0; i < height_; ++i) {
    field_.push_back(QVector<Cell>());
    for (int j = 0; j < width_; ++j) {
      field_[i].push_back(Cell(snapshot.At(i, j)));
    }
  }
}

QVector<Grid::Index> Grid::Update() {
  QVector<Index> result;
  auto old_cells = field_;
  for (int i = 0; i < old_cells.size(); ++i) {
    for (int j = 0; j < old_cells[i].size(); ++j) {
      unsigned int numberOfAliveNeighbours = NumberOfAliveNeighbours(i, j, old_cells);
      Cell cell = old_cells[i][j];
      if (cell.IsDead() && numberOfAliveNeighbours == 3) {
        field_[i][j].SetAlive();
        result.push_back(Index{i, j});
      } else if (cell.IsAlive() && numberOfAliveNeighbours < 2) {
        field_[i][j].SetDead();
        result.push_back(Index{i, j});
      } else if (cell.IsAlive() && numberOfAliveNeighbours > 3) {
        field_[i][j].SetDead();
        result.push_back(Index{i, j});
      }
    }
  }
  return result;
}

unsigned int Grid::NumberOfAliveNeighbours(int i, int j, const QVector<QVector<Cell>> &field) const {
  unsigned int result = 0;
  for (int x = -1; x <= 1; ++x) {
    for (int y = -1; y <= 1; ++y) {
      if (x != 0 || y != 0)
        if (IsCorrectIndex(i + x, j + y)) {
          result += field[i + x][j + y].IsAlive();
        }
    }
  }
  return result;
}

bool Grid::IsCorrectIndex(int i, int j) const {
  return i >= 0 && i < height_ && j >= 0 && j < width_;
}

Cell Grid::At(Index index) const {
  return field_[index.i][index.j];
}

unsigned int Grid::Height() const {
  return height_;
}

unsigned int Grid::Width() const {
  return width_;
}
Cell Grid::At(int i, int j) const {
  return field_[i][j];
}
