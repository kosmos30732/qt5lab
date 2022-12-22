#include "static.h"
#include <QMessageBox>

void say_static(QWidget* parent)
{
	QMessageBox msg(parent);
	msg.setText("Static library!");
	msg.exec();
}
