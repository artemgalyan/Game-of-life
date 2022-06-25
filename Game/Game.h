#ifndef GAMEOFLIFE_GAME_GAME_H_
#define GAMEOFLIFE_GAME_GAME_H_

#include "../controller/GridController.h"
#include "../logic/FieldSnapshot/FieldSnapshot.h"
#include "../logic/Grid.h"
#include "../ui/field/gamefield.h"
#include "../Settings/Settings.h"

class Game : public QObject {
 public:
  explicit Game(int width, int height, unsigned int frametime = 500);
  GameField* GetGameField() const;
  ~Game();
  void Run();
  void Pause();
  void DrawField();
 private slots:
  void Update();
 private:
  Grid* grid_;
  GridController* grid_controller_;
  GameField* game_field_;
  QTimer* timer_;
  unsigned int frame_time_;
};

#endif //GAMEOFLIFE_GAME_GAME_H_
