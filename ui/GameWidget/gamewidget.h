#ifndef GAMEOFLIFE_UI_GAMEWIDGET_GAMEWIDGET_H_
#define GAMEOFLIFE_UI_GAMEWIDGET_GAMEWIDGET_H_

#include <QWidget>

#include <QGraphicsView>

QT_BEGIN_NAMESPACE
namespace Ui { class GameWidget; }
QT_END_NAMESPACE

class GameWidget : public QWidget {
 Q_OBJECT

 public:
  explicit GameWidget(QWidget *parent = nullptr);
  ~GameWidget() override;
  void SetScene(QGraphicsScene*);
 protected:
  void resizeEvent(QResizeEvent *event) override;
 private:
  Ui::GameWidget *ui;
  QGraphicsView* gv_;
};

#endif //GAMEOFLIFE_UI_GAMEWIDGET_GAMEWIDGET_H_
