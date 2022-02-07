#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QComboBox>

class MyComboBox : public QComboBox
{
public:
    MyComboBox();
    void showPopup();
};

#endif // MYCOMBOBOX_H
