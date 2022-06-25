#include "GridController.h"

void GridController::Update() {
  auto updateResult = grid_->Update();
  for (auto index: updateResult) {
    cells_[index.i][index.j]->setBrush(grid_->At(index).IsAlive() ? Settings::AliveBrush() : Settings::DeadBrush());
  }
}

GridController::GridController(Grid *grid, GameField *game_field)
    : grid_(grid), game_field_(game_field) {}

void GridController::DrawField() {
  for (int i = 0; i < grid_->Height(); ++i) {
    cells_.push_back(QVector<QGraphicsRectItem*>());
    for (int j = 0; j < grid_->Width(); ++j) {
      QBrush brush = grid_->At(i, j).IsAlive() ? Settings::AliveBrush() : Settings::DeadBrush();
      auto cell = game_field_->DrawCell(Settings::GetPen(), brush, i, j);
      cells_[i].push_back(cell);
    }
  }
}