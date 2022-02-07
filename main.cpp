#include "mainwindow.h"
#include <QApplication>
#include <QComboBox>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>

QString Sam[] {
    "Cy-35",
    "T-50",
    "Cy-27",
    "Cy-34"
};

int main(int argc, char* argv[])
{
    Beep(247, 500);

    QApplication a(argc, argv);

    QDialog* d = new QDialog();
    QVBoxLayout* LayoutPar = new QVBoxLayout(d);
    d->setLayout(LayoutPar);

    QLineEdit* le = new QLineEdit("");
    LayoutPar->addWidget(le);

    bool pr = false;

    le->connect(le, &QLineEdit::returnPressed,
        [&]() {
            if (QString().number(1) == le->text())
                pr = true;
            d->accept();
        });

    d->exec();
    d->deleteLater();

    if (pr) {
        d = new QDialog();
        LayoutPar = new QVBoxLayout(d);
        d->setLayout(LayoutPar);
        QComboBox* cb = new QComboBox();
        for (int fooInt = Cy_35; fooInt <= Cy_34; fooInt++) {
            cb->addItem(Sam[fooInt]);
        }
        QFont font = cb->font();
        //font.setPointSize(20);
        cb->setFont(font);
        LayoutPar->addWidget(cb);

        void (QComboBox::*Sender)(int index) = &QComboBox::activated;

        cb->connect(cb, Sender,
            [&](int i) {
                //d->accept();
                MainWindow* w = new MainWindow((SamEnum)i);
                w->show();
            });
        d->show();
        //d->deleteLater();
    } else {
        d = new QDialog(0, Qt::CustomizeWindowHint | Qt::WindowTitleHint);
        d->setMinimumWidth(500);
        LayoutPar = new QVBoxLayout(d);
        d->setLayout(LayoutPar);
        QLabel* le = new QLabel("Диск С: отформатируется через : 10");
        QFont font = le->font();
        //font.setPointSize(20);
        le->setFont(font);
        LayoutPar->addWidget(le);

        QProgressBar* pb = new QProgressBar();

        QTimer* t = new QTimer();
        t->start(1000);
        int sch = 10;

        t->connect(t, &QTimer::timeout,
            [&]() {
                Beep(247, 500);
                sch--;
                if (sch < 0) {
                    LayoutPar->addWidget(pb);
                    le->setText("Форматируется диск С:");
                    if (pb->value() + 1 != 100)
                        pb->setValue(pb->value() + 1);
                    else
                        d->accept();
                    t->start(300);
                }
                if (sch == -1000) {
                    d->accept();
                }
                if (sch > 0) {
                    le->setText("Диск С: отформатируется через : " + QString().number(sch));
                }
            });

        d->exec();
        d->deleteLater();

        return 0;
    }

    return a.exec();
}
