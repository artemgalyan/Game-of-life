#include "Settings.h"

unsigned Settings::pen_width_ = 0;

QColor Settings::pen_color_ = Qt::GlobalColor::black;
QColor Settings::dead_color_ = Qt::GlobalColor::black;
QColor Settings::alive_color_ = Qt::GlobalColor::red;

QColor Settings::PenColor() {
  return pen_color_;
}

QColor Settings::AliveColor() {
  return alive_color_;
}
QColor Settings::DeadColor() {
  return dead_color_;
}
unsigned Settings::PenWidth() {
  return pen_width_;
}

QPen Settings::GetPen() {
  return QPen(pen_color_, pen_width_);
}

QBrush Settings::DeadBrush() {
  return QBrush(dead_color_);
}
QBrush Settings::AliveBrush() {
  return QBrush(alive_color_);
}

