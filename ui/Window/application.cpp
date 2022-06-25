//
// Created by tyoma on 23.06.2022.
//


#include "application.h"
#include "ui_Application.h"

Application::Application(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Application) {
  ui->setupUi(this);
}

Application::~Application() {
  delete ui;
}
