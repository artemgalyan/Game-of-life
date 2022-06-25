#include "cell.h"

Cell::Cell(bool alive) : alive_(alive) {}

bool Cell::IsAlive() const {
  return alive_;
}
bool Cell::IsDead() const {
  return !alive_;
}
void Cell::SetAlive() {
  alive_ = true;
}
void Cell::SetDead() {
  alive_ = false;
}
