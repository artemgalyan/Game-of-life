#ifndef GAMEOFLIFE_UI_WINDOW_APPLICATION_H_
#define GAMEOFLIFE_UI_WINDOW_APPLICATION_H_

#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Application; }
QT_END_NAMESPACE

class Application : public QMainWindow {
 Q_OBJECT

 public:
  explicit Application(QWidget *parent = nullptr);
  ~Application() override;

 private:
  Ui::Application *ui;
};

#endif //GAMEOFLIFE_UI_WINDOW_APPLICATION_H_
