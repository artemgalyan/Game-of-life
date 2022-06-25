#ifndef GAMEOFLIFE_SETTINGS_SETTINGS_H_
#define GAMEOFLIFE_SETTINGS_SETTINGS_H_

#include <QColor>
#include <QPen>
#include <QBrush>

class Settings {
 public:
  static QColor PenColor();
  static QColor AliveColor();
  static QColor DeadColor();
  static unsigned PenWidth();
  static QPen GetPen();
  static QBrush DeadBrush();
  static QBrush AliveBrush();
 private:
  static QColor pen_color_;
  static QColor alive_color_;
  static QColor dead_color_;
  static unsigned pen_width_;
};
#endif //GAMEOFLIFE_SETTINGS_SETTINGS_H_
