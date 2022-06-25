#include "FieldSnapshot.h"

#include <random>

#include <QDebug>

FieldSnapshot::FieldSnapshot(int width, int height) {
  field_ = QVector<QVector<bool>>(height, QVector<bool>(width));
}

bool FieldSnapshot::At(int i, int j) const {
  return field_[i][j];
}

QVector<bool> &FieldSnapshot::operator[](int index) {
  return field_[index];
}
unsigned int FieldSnapshot::Width() const {
  if (field_.isEmpty())
    return 0;
  return field_[0].size();
}
unsigned int FieldSnapshot::Height() const {
  return field_.size();
}
FieldSnapshot::FieldSnapshot(FieldSnapshot &&fs) noexcept {
  field_ = std::move(fs.field_);
}

FieldSnapshot FieldSnapshot::GenerateFieldSnapshot(int width, int height) {
  FieldSnapshot fs(width, height);
  std::random_device rd;
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      fs.field_[i][j] = rd() % 2;
    }
  }
  return fs;
}
