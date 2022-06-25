#include "Game.h"

#include <QTimer>

Game::Game(int width, int height, unsigned int frametime) {
  frame_time_ = frametime;
  auto snap = FieldSnapshot::GenerateFieldSnapshot(width, height);
  grid_ = new Grid(snap);
  game_field_ = new GameField(width, height);
  grid_controller_ = new GridController(grid_, game_field_);
  timer_ = new QTimer();
  connect(timer_, &QTimer::timeout, this, &Game::Update);
}

GameField *Game::GetGameField() const {
  return game_field_;
}
Game::~Game() {
  delete grid_;
  delete game_field_;
}

void Game::Run() {
  timer_->start(frame_time_);
}

void Game::Update() {
  grid_controller_->Update();
  game_field_->update();
}

void Game::DrawField() {
  grid_controller_->DrawField();
}
