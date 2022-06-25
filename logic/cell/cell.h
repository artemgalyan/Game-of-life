#ifndef GAMEOFLIFE_LOGIC_CELL_CELL_H_
#define GAMEOFLIFE_LOGIC_CELL_CELL_H_

class Cell {
 public:
  Cell(bool alive);
  bool IsAlive() const;
  bool IsDead() const;
  void SetAlive();
  void SetDead();
 private:
  bool alive_;
};

#endif //GAMEOFLIFE_LOGIC_CELL_CELL_H_
