#ifndef GAMEOFLIFE_LOGIC_FIELDSNAPSHOT_FIELDSNAPSHOT_H_
#define GAMEOFLIFE_LOGIC_FIELDSNAPSHOT_FIELDSNAPSHOT_H_

#include <QVector>

class FieldSnapshot {
 public:
  static FieldSnapshot GenerateFieldSnapshot(int width, int height);
  FieldSnapshot(FieldSnapshot&&) noexcept;
  FieldSnapshot(int width, int height);
  [[nodiscard]] bool At(int i, int j) const;
  QVector<bool>& operator[](int index);
  [[nodiscard]] unsigned int Width() const;
  [[nodiscard]] unsigned int Height() const;
 private:
  QVector<QVector<bool>> field_;
};

#endif //GAMEOFLIFE_LOGIC_FIELDSNAPSHOT_FIELDSNAPSHOT_H_
