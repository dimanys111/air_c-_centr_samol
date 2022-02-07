#include "mycombobox.h"
#include "QAbstractItemView"

MyComboBox::MyComboBox()
{

}

void MyComboBox::showPopup()
{
    this->view()->setMinimumWidth(this->view()->sizeHintForColumn(0));
    QComboBox::showPopup();
}
