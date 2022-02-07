#ifndef TOCHPODVES_H
#define TOCHPODVES_H

#include <QCheckBox>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QVBoxLayout>
#include <mycombobox.h>

class Podves;
class MainWindow;

enum SamEnum {
    Cy_35 = 0,
    T_50 = 1,
    Cy_27 = 2,
    Cy_34 = 3
};

class TochPodves : public QVBoxLayout {
    Q_OBJECT

public:
    int nom;
    int kol;
    float z;
    bool isAct;
    Podves* podv;
    QCheckBox* cb;
    MyComboBox* cbl;
    QSpinBox* sb;
    QList<float> Mass;
    QList<float> x;
    float MassIzd;
    float xIzd;
    int is;
    TochPodves(float z_, int n, MainWindow* mw);
    void setPodv();

private:
    MainWindow* mw;
    SamEnum sam;
};

#endif // TOCHPODVES_H
