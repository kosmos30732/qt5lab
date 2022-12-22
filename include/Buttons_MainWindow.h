#include <QPushButton>

class Buttons_MainWindow
{
public:
	QPushButton *button_foo_, *button_bar_, *button_baz_, *bazligth_;

    explicit Buttons_MainWindow(QWidget* parent)
    {
        button_foo_= new QPushButton("Button Foo", parent);
		button_foo_->setGeometry(10, 50, 130, 20);
		button_bar_= new QPushButton("Button Bar", parent);
		button_bar_->setGeometry(100, 150, 100, 35);
		button_baz_= new QPushButton("Button Baz", parent);
		button_baz_->setGeometry(10, 250, 150, 50);
		bazligth_= new QPushButton("Bazligther", parent);
		bazligth_->setGeometry(10, 350, 100, 100);
		
    };

    ~Buttons_MainWindow()
    {

    };
};
