#include "dynamic.h"
#include <QMessageBox>

void say_dynamic(QWidget* parent)
{
	QMessageBox msg(parent);
	msg.setText("Dynamic library!");
	msg.exec();
}
