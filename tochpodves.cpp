#include "tochpodves.h"
#include "mainwindow.h"
#include <QString>

#include "podves.h"

void TochPodves::setPodv()
{
    QString s = cbl->currentText();
    int i = 0;
    for (auto& var : mw->listPodves) {
        if (var.Name == s) {
            break;
        }
        i++;
    }
    podv = &mw->listPodves[i];

    Mass.clear();
    x.clear();
    int kol {};

    switch (sam) {
    case Cy_35:
        kol = 1;
        break;
    case T_50:
        kol = 2;
        break;
    default:
        break;
    }

    i = 1;
    for (; i < podv->slTabl.size() - 1; i++) {
        Mass << podv->slTabl.at(i).at(is).toFloat() / kol;
        x << podv->slTabl.at(i).at(is + 1).toFloat();
    }
    MassIzd = podv->slTabl.at(i).at(is).toFloat() / kol;
    xIzd = podv->slTabl.at(i).at(is + 1).toFloat();
}

TochPodves::TochPodves(float z_, int n, MainWindow* mw)
    : sam(mw->sam)
{
    isAct = false;
    z = z_;
    kol = 1;
    nom = n;
    sb = new QSpinBox();
    void (QSpinBox::*Sender0)(int index) = &QSpinBox::valueChanged;
    connect(sb, Sender0,
        [&](int i) {
            kol = i;
        });
    sb->setMinimum(1);
    cb = new QCheckBox(QString().number(nom));
    cbl = new MyComboBox();
    connect(cb, &QCheckBox::stateChanged,
        [&](int j) {
            setPodv();
            isAct = j;
            cbl->setEnabled(j);
            sb->setEnabled(j);
        });
    void (QComboBox::*Sender)(const QString& s) = &QComboBox::activated;
    cb->setChecked(false);
    cbl->setEnabled(false);
    sb->setEnabled(false);

    switch (sam) {
    case Cy_35:
        switch (n) {
        case 1:
            is = 2;
            break;
        case 2:
            is = 4;
            break;
        case 3:
            is = 6;
            break;
        case 4:
            is = 6;
            break;
        case 5:
            is = 8;
            break;
        case 6:
            is = 8;
            break;
        case 7:
            is = 10;
            break;
        case 8:
            is = 10;
            break;
        case 9:
            is = 12;
            break;
        case 10:
            is = 12;
            break;
        case 11:
            is = 14;
            break;
        case 12:
            is = 14;
            break;
        default:
            break;
        }
        break;

    case T_50:
        switch (n) {
        case 1:
            is = 2;
            break;
        case 2:
            is = 2;
            break;
        case 3:
            is = 4;
            break;
        case 4:
            is = 4;
            break;
        case 5:
            is = 6;
            break;
        case 6:
            is = 6;
            break;
        case 7:
            is = 8;
            break;
        case 8:
            is = 8;
            break;
        case 9:
            is = 10;
            break;
        case 10:
            is = 10;
            break;
        case 11:
            is = 12;
            break;
        case 12:
            is = 12;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    connect(cbl, Sender,
        [&](const QString& s1) {
            setPodv();
        });

    for (Podves& var : mw->listPodves) {
        if (var.slTabl.at(0).at(is) != "" && var.slTabl.at(0).at(is) != "-----") {
            cbl->addItem(var.Name);
        }
    }

    QHBoxLayout* l = new QHBoxLayout();
    l->setAlignment(Qt::AlignCenter);
    l->addWidget(cb);
    addLayout(l);
    addWidget(cbl);
    addWidget(sb);
}
