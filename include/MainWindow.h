#include <QMainWindow>
#include "Buttons_MainWindow.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT
public slots:
  static void static_txt();
  static void dynamic_txt();
  
public:
  explicit MainWindow(QWidget *parent = nullptr);
  virtual ~MainWindow();
  
private:
  Buttons_MainWindow* buttons;
};
