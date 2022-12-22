#include "MainWindow.h"
#include "static.h"
#include "dynamic.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
	setWindowTitle("Some Main Window");
	resize(600, 600);
	this->buttons = new Buttons_MainWindow(this);
	connect(buttons->button_foo_, &QPushButton::released, this, &MainWindow::static_txt);
	connect(buttons->button_bar_, &QPushButton::released, this, &MainWindow::dynamic_txt);
}

MainWindow::~MainWindow(){ }

void MainWindow::static_txt()
{
  say_static();
}

void MainWindow::dynamic_txt()
{
  say_dynamic();
}
