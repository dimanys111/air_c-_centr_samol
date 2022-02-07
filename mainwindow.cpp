#include "mainwindow.h"
#include "QFile"
#include "QHBoxLayout"
#include "QLabel"
#include "QLineEdit"
#include "QPushButton"
#include "QTextCodec"
#include "QTextStream"
#include "ui_mainwindow.h"

#include "tochpodves.h"

#include <QCoreApplication>

void MainWindow::T_50_(QGridLayout* grl)
{
    momShass.setMom(1300);
    QFile filePodves(qApp->applicationDirPath() + "/zzz.csv");
    if (filePodves.open(QFile::ReadOnly)) {
        QTextCodec* codec = QTextCodec::codecForName("cp1251");
        QTextStream in(&filePodves);
        in.setCodec(codec);

        QString s = in.readLine();
        QStringList sl = s.split(";");
        while (sl.at(0) != "1") {
            s = in.readLine();
            sl = s.split(";");
        }
        Podves p;
        while (!in.atEnd()) {
            p << sl;
            s = in.readLine();
            sl = s.split(";");
            if (sl.at(0) != "") {
                p.setName();
                MainWindow::listPodves << p;
                p = Podves();
            }
        }
        p << sl;
        p.setName();
        MainWindow::listPodves << p;
        filePodves.close();
    }

    QFile fileCentr(qApp->applicationDirPath() + "/zzz1.csv");
    if (fileCentr.open(QFile::ReadOnly)) {
        QTextCodec* codec = QTextCodec::codecForName("cp1251");
        QTextStream in(&fileCentr);
        in.setCodec(codec);

        QString s = in.readLine();
        QStringList sl = s.split(";");

        do {
            momSam << elemMom(sl);
            s = in.readLine();
            sl = s.split(";");
        } while (sl.at(0) != "");

        s = in.readLine();
        sl = s.split(";");

        do {
            momOrug << elemMom(sl);
            s = in.readLine();
            sl = s.split(";");
        } while (sl.at(0) != "");

        s = in.readLine();
        sl = s.split(";");

        do {
            momTopl1 << elemMom(sl);
            s = in.readLine();
            sl = s.split(";");
        } while (sl.at(0) != "" || !in.atEnd());

        fileCentr.close();
    }

    tochpodv << new TochPodves(0.23, 1, this);
    tochpodv << new TochPodves(-0.23, 2, this);
    tochpodv << new TochPodves(0.23, 3, this);
    tochpodv << new TochPodves(-0.23, 4, this);
    tochpodv << new TochPodves(2.443, 5, this);
    tochpodv << new TochPodves(-2.443, 6, this);
    tochpodv << new TochPodves(1.29, 7, this);
    tochpodv << new TochPodves(-1.29, 8, this);
    tochpodv << new TochPodves(3.885, 9, this);
    tochpodv << new TochPodves(-3.885, 10, this);
    tochpodv << new TochPodves(4.985, 11, this);
    tochpodv << new TochPodves(-4.985, 12, this);

    int nomKol = 5;

    grl->addLayout(tochpodv[11], nomKol, 0);
    grl->addLayout(tochpodv[9], nomKol, 1);
    grl->addLayout(tochpodv[5], nomKol, 2);
    grl->addLayout(tochpodv[7], nomKol, 3);
    grl->addLayout(tochpodv[3], nomKol, 4);
    grl->addLayout(tochpodv[2], nomKol, 5);
    grl->addLayout(tochpodv[1], nomKol + 1, 4);
    grl->addLayout(tochpodv[0], nomKol + 1, 5);
    grl->addLayout(tochpodv[6], nomKol, 6);
    grl->addLayout(tochpodv[4], nomKol, 7);
    grl->addLayout(tochpodv[8], nomKol, 8);
    grl->addLayout(tochpodv[10], nomKol, 9);
}

void MainWindow::Cy_35_(QGridLayout* grl)
{
    momShass.setMom(1610);
    QFile filePodves(qApp->applicationDirPath() + "/p35.csv");
    if (filePodves.open(QFile::ReadOnly)) {
        QTextCodec* codec = QTextCodec::codecForName("cp1251");
        QTextStream in(&filePodves);
        in.setCodec(codec);

        QString s = in.readLine();
        QStringList sl = s.split(";");
        while (sl.at(0) != "1") {
            s = in.readLine();
            sl = s.split(";");
        }
        Podves p;
        while (!in.atEnd()) {
            if (sl.at(0) != "") {
                if (!MainWindow::listPodves.isEmpty())
                    p.setName();
                MainWindow::listPodves << p;
                p = Podves();
            }
            p << sl;
            s = in.readLine();
            sl = s.split(";");
        }
        p << sl;
        if (!MainWindow::listPodves.isEmpty())
            p.setName();
        MainWindow::listPodves << p;
        MainWindow::listPodves.removeFirst();
        filePodves.close();
    }

    QFile fileCentr(qApp->applicationDirPath() + "/c35.csv");
    if (fileCentr.open(QFile::ReadOnly)) {
        QTextCodec* codec = QTextCodec::codecForName("UTF-8");
        QTextStream in(&fileCentr);
        in.setCodec(codec);

        QString s = in.readLine();
        QStringList sl = s.split(";");
        while (sl.at(0) != "") {
            momSam << elemMom(sl);
            s = in.readLine();
            sl = s.split(";");
        }
        s = in.readLine();
        sl = s.split(";");
        while (sl.at(0) != "") {
            momOrug << elemMom(sl);
            s = in.readLine();
            sl = s.split(";");
        }
        s = in.readLine();
        sl = s.split(";");
        while (sl.at(0) != "") {
            momTopl1 << elemMom(sl);
            s = in.readLine();
            sl = s.split(";");
        }
        s = in.readLine();
        sl = s.split(";");
        while (!in.atEnd()) {
            momTopl2 << elemMom(sl);
            s = in.readLine();
            sl = s.split(";");
        }
        momTopl2 << elemMom(sl);
        fileCentr.close();
    }

    tochpodv << new TochPodves(0.0, 1, this);
    tochpodv << new TochPodves(0.0, 2, this);
    tochpodv << new TochPodves(4.64, 3, this);
    tochpodv << new TochPodves(-4.64, 4, this);
    tochpodv << new TochPodves(6.22, 5, this);
    tochpodv << new TochPodves(-6.22, 6, this);
    tochpodv << new TochPodves(7.35, 7, this);
    tochpodv << new TochPodves(-7.35, 8, this);
    tochpodv << new TochPodves(1.2, 9, this);
    tochpodv << new TochPodves(-1.2, 10, this);
    tochpodv << new TochPodves(3.52, 11, this);
    tochpodv << new TochPodves(-3.52, 12, this);

    int nomKol = 5;

    grl->addLayout(tochpodv[8], nomKol, 0);
    grl->addLayout(tochpodv[6], nomKol, 1);
    grl->addLayout(tochpodv[4], nomKol, 2);
    grl->addLayout(tochpodv[12], nomKol, 3);
    grl->addLayout(tochpodv[10], nomKol, 4);

    grl->addLayout(tochpodv[2], nomKol + 1, 5);
    grl->addLayout(tochpodv[1], nomKol, 5);

    grl->addLayout(tochpodv[9], nomKol, 6);
    grl->addLayout(tochpodv[11], nomKol, 7);
    grl->addLayout(tochpodv[3], nomKol, 8);
    grl->addLayout(tochpodv[5], nomKol, 9);
    grl->addLayout(tochpodv[7], nomKol, 10);
}

void MainWindow::plotGraph(QString& TextPodw, float max_x, QList<QVector<double>>& centrS_y, float min_y, float min_x, QList<QVector<double>>& centrS_x, float max_y)
{
    QCustomPlot* cp = new QCustomPlot();
    //connect(cp,&QCustomPlot::plottableClick,this,&MainWindow::plottableClick);
    connect(cp, &QCustomPlot::mousePress, this, &MainWindow::plotMousePress);
    cp->setInteraction(QCP::iRangeDrag, true);
    cp->setInteraction(QCP::iRangeZoom, true);
    cp->setInteraction(QCP::iSelectPlottables, true);
    cp->setWindowTitle(TextPodw);
    cp->resize(600, 700);
    for (int i = 0; i < centrS_x.size(); i++) {
        QCPCurve* newCurve1 = new QCPCurve(cp->xAxis, cp->yAxis);
        newCurve1->setScatterStyle(QCPScatterStyle::ssCircle);
        QColor col;
        Qt::PenStyle s;
        if (i % 2 == 0)
            s = Qt::DashLine;
        else
            s = Qt::SolidLine;
        if (i > 1)
            col = Qt::red;
        else
            col = Qt::blue;

        newCurve1->setPen(QPen(col, 1, s));
        newCurve1->setData(centrS_x.at(i), centrS_y.at(i));
    }

    cp->plottable(0)->setName("Шасси вып.");
    cp->plottable(1)->setName("Шасси убр.");
    if (centrS_x.size() > 2) {
        cp->plottable(2)->setName("Шасси вып. " + TextPodw);
        cp->plottable(3)->setName("Шасси убр. " + TextPodw);
    }

    cp->xAxis->setLabel("Центровка");
    cp->xAxis->ticker().data()->setTickCount(max_x - min_x + 4);
    cp->yAxis->setLabel("Масса");
    cp->yAxis->ticker().data()->setTickCount((max_y - min_y) / 1000 + 4);
    cp->xAxis->setRange(min_x - 2, max_x + 2);
    cp->yAxis->setRange(min_y - 1000, max_y + 1000);
    cp->replot();
    cp->show();
}

void MainWindow::rasMinMax(float& max_y, float& min_x, QList<QVector<double>>& centrS_y, float& min_y, QList<QVector<double>>& centrS_x, float& max_x)
{
    for (int i = 0; i < centrS_x.size(); i++) {
        QVector<double> x = centrS_x.at(i);
        for (int j = 0; j < x.size(); j++) {
            if (x.at(j) > max_x)
                max_x = x.at(j);
            if (x.at(j) < min_x)
                min_x = x.at(j);
        }
    }
    max_x = max_x;
    min_x = min_x;
    leXt->setText(QString().number(max_x));

    for (int i = 0; i < centrS_y.size(); i++) {
        QVector<double> y = centrS_y.at(i);
        for (int j = 0; j < y.size(); j++) {
            if (y.at(j) > max_y)
                max_y = y.at(j);
            if (y.at(j) < min_y)
                min_y = y.at(j);
        }
    }
    max_y = max_y;
    min_y = min_y;
}

void MainWindow::rasToplMom(QList<QVector<double>>& centrS_y, float sumMom, float MomPodv, float sumMass, float MassPodv, bool bPodv, QList<QVector<double>>& centrS_x)
{
    QVector<double> centrSV_T1_x;
    QVector<double> centrSU_T1_x;
    QVector<double> centr_T1_y;

    QVector<double> centrSV_T1_P_x;
    QVector<double> centrSU_T1_P_x;

    float x_b {};
    float b_a {};

    switch (sam) {
    case Cy_35:
        x_b = 10.24;
        b_a = 4.645;
        break;
    case T_50:
        x_b = 8.64;
        b_a = 7.136;
        break;
    default:
        break;
    }

    float sumMomTopl = sumMom;
    float sumMassTopl = sumMass;
    for (auto& i : momTopl1) {
        sumMomTopl = sumMomTopl + i.moment;
        sumMassTopl = sumMassTopl + i.mass;
        float XC_SV = (sumMomTopl / sumMassTopl - x_b) * 100 / b_a;
        float XC_SU = ((sumMomTopl - momShass.moment) / sumMassTopl - x_b) * 100 / b_a;
        centrSV_T1_x << XC_SV;
        centrSU_T1_x << XC_SU;
        centr_T1_y << sumMassTopl - sumMass;

        if (bPodv) {
            float XC_SV_P = ((sumMomTopl + MomPodv) / (sumMassTopl + MassPodv) - x_b) * 100 / b_a;
            float XC_SU_P = ((sumMomTopl + MomPodv - momShass.moment) / (sumMassTopl + MassPodv) - x_b) * 100 / b_a;
            centrSV_T1_P_x << XC_SV_P;
            centrSU_T1_P_x << XC_SU_P;
            //centr_T1_P_y<<sumMassTopl-sumMass+MassPodv;
        }
    }
    centrS_x << centrSV_T1_x;
    centrS_y << centr_T1_y;
    centrS_x << centrSU_T1_x;
    centrS_y << centr_T1_y;
    if (bPodv) {
        centrS_x << centrSV_T1_P_x;
        centrS_y << centr_T1_y;
        centrS_x << centrSU_T1_P_x;
        centrS_y << centr_T1_y;
    }
}

void MainWindow::rasPodv(bool& bPodv, float& MomPodv, float& MassPodv, float& MomZPodv, QString& TextPodw)
{
    for (TochPodves* var : tochpodv) {
        if (var->isAct) {
            bPodv = true;
            int kol = var->kol;
            float MassPodv_ {};
            for (int i = 0; i < var->Mass.size(); i++) {
                MomPodv = MomPodv + var->Mass.at(i) * var->x.at(i);
                MassPodv_ = MassPodv_ + var->Mass.at(i);
            }
            MomPodv = MomPodv + var->MassIzd * kol * var->xIzd;
            MassPodv_ = MassPodv_ + var->MassIzd * kol;
            MomZPodv = MomZPodv + MassPodv_ * var->z;
            MassPodv = MassPodv + MassPodv_;
            TextPodw = TextPodw + QString().number(var->nom) + " ТП " + QString().number(kol) + " шт " + var->podv->Name + ";";
        }
    }
    leMnes->setText(QString().number(MomZPodv));
}

void MainWindow::raschMom()
{
    float sumMom = 0.0;
    float sumMass = 0.0;
    for (elemMom& var : momSam) {
        sumMom = sumMom + var.moment;
        sumMass = sumMass + var.mass;
    }
    for (elemMom& var : momOrug) {
        sumMom = sumMom + var.moment;
        sumMass = sumMass + var.mass;
    }

    float MomPodv = 0.0;
    float MomZPodv = 0.0;
    float MassPodv = 0.0;
    bool bPodv = false;
    QString TextPodw;
    rasPodv(bPodv, MomPodv, MassPodv, MomZPodv, TextPodw);

    QList<QVector<double>> centrS_x;
    QList<QVector<double>> centrS_y;
    if (momTopl1.size()) {
        rasToplMom(centrS_y, sumMom, MomPodv, sumMass, MassPodv, bPodv, centrS_x);
    }

    float min_x = 1000000;
    float max_x = -1000000;
    float min_y = 1000000;
    float max_y = -1000000;
    rasMinMax(max_y, min_x, centrS_y, min_y, centrS_x, max_x);

    if (boolGraf) {
        plotGraph(TextPodw, max_x, centrS_y, min_y, min_x, centrS_x, max_y);
    }
}

void MainWindow::plottableClick(QCPAbstractPlottable* plottable, int dataIndex, QMouseEvent* event)
{
    QCustomPlot* cp = (QCustomPlot*)QObject::sender();
    double key, value;
    plottable->pixelsToCoords(event->pos(), key, value);
    QToolTip::showText(cp->mapToGlobal(event->pos()),
        "x=" + QString().number(key) + "|y=" + QString().number(value), cp);
}

void MainWindow::open_file(QString files)
{
    if (files == "")
        files = QFileDialog::getOpenFileName(nullptr, "Open Dialog", QCoreApplication::applicationDirPath(), "cen (*.cen)");
    if (files != "") {
        QFile file(files);
        if (file.open(QIODevice::ReadOnly)) {
            QDataStream stream(&file);
            stream.setVersion(QDataStream::Qt_5_4);
            int i;
            stream >> i;
            if (i == tochpodv.size())
                for (auto t : tochpodv) {
                    if (stream.atEnd())
                        return;
                    int i;
                    stream >> i;
                    stream >> t->isAct;
                    t->cbl->setCurrentIndex(i);
                    t->cb->setChecked(t->isAct);
                }
        }
    }
}

void MainWindow::save_file(QString files)
{
    if (files == "")
        files = QFileDialog::getSaveFileName(nullptr, "Save Dialog", QCoreApplication::applicationDirPath(), "cen (*.cen)");

    if (files != "") {
        if (files.section(".", -1, -1) != "cen") {
            files += ".cen";
        }

        QFile file(files);
        if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            QDataStream stream(&file);
            stream.setVersion(QDataStream::Qt_5_4);
            stream << tochpodv.size();
            for (auto t : tochpodv) {
                stream << t->cbl->currentIndex();
                stream << t->isAct;
            }

            file_save = files;
        }
    }
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    save_file(QCoreApplication::applicationDirPath() + "/1.cen");
    deleteLater();
}

void MainWindow::plotMousePress(QMouseEvent* event)
{
    QCustomPlot* cp = (QCustomPlot*)QObject::sender();
    if (event->button() == Qt::LeftButton) {
        QCPAbstractPlottable* plottable = cp->plottableAt(event->pos());

        if (plottable) {
            double x = cp->xAxis->pixelToCoord(event->pos().x());
            double y = cp->yAxis->pixelToCoord(event->pos().y());

            QCPCurve* curve = qobject_cast<QCPCurve*>(plottable);

            if (curve) {
                double key = 0;
                double value = 0;

                bool ok = false;
                double m = std::numeric_limits<double>::max();

                QCPDataContainer<QCPCurveData>::iterator it; //объявляю итератор it

                for (it = curve->data().data()->begin(); it != curve->data().data()->end(); it++) {
                    double d = qSqrt(qPow(x - it->mainKey(), 2) + qPow(y - it->mainValue(), 2));

                    if (d < m) {
                        key = it->mainKey();
                        value = it->mainValue();

                        ok = true;
                        m = d;
                    }
                }

                if (ok) {
                    QToolTip::hideText();
                    QToolTip::showText(event->globalPos(),
                        tr("<table>"
                           "<tr>"
                           "<th colspan=\"2\">%L1</th>"
                           "</tr>"
                           "<tr>"
                           "<td>X:</td>"
                           "<td>%L2</td>"
                           "</tr>"
                           "<tr>"
                           "<td>Y:</td>"
                           "<td>%L3</td>"
                           "</tr>"
                           "</table>")
                            .arg(curve->name().isEmpty() ? "..." : curve->name())
                            .arg(key)
                            .arg(value),
                        cp, cp->rect());
                }
            }
        }
    }
}

void MainWindow::setOutElement(QGridLayout* grl)
{
    QLabel* labMass = new QLabel("Масса пустого:");
    leMass = new QLineEdit("18740");
    connect(leMass, &QLineEdit::textChanged,
        [&](const QString& s) {
            momSam[0].setMass(s.toFloat());
        });
    QHBoxLayout* layMass = new QHBoxLayout();
    layMass->addWidget(labMass);
    layMass->addWidget(leMass);
    grl->addLayout(layMass, 0, grl->columnCount() - 2, 1, 2);

    QLabel* labCyGp = new QLabel("Cyгп =");
    leCyGp = new QLineEdit("");
    QHBoxLayout* layCyGp = new QHBoxLayout();
    layCyGp->addWidget(labCyGp);
    layCyGp->addWidget(leCyGp);
    grl->addLayout(layCyGp, 0, 0, 1, 2);

    QLabel* labXt = new QLabel("Xт =");
    leXt = new QLineEdit("");
    QHBoxLayout* layXt = new QHBoxLayout();
    layXt->addWidget(labXt);
    layXt->addWidget(leXt);
    grl->addLayout(layXt, 1, 0, 1, 2);

    QLabel* labMnes = new QLabel("Mнес =");
    leMnes = new QLineEdit("");
    QHBoxLayout* layMnes = new QHBoxLayout();
    layMnes->addWidget(labMnes);
    layMnes->addWidget(leMnes);
    grl->addLayout(layMnes, 2, 0, 1, 2);

    QPushButton* butRasch = new QPushButton("Расчитать");
    connect(butRasch, &QPushButton::clicked,
        [&]() {
            raschMom();
        });
    grl->addWidget(butRasch, 3, 0, 1, 2);

    QPushButton* but_zagr = new QPushButton("Загрузить");
    connect(but_zagr, &QPushButton::clicked,
        [&]() {
            open_file();
        });
    grl->addWidget(but_zagr, 4, 0, 1, 1);

    QPushButton* but_save = new QPushButton("Сохранить");
    connect(but_save, &QPushButton::clicked,
        [&]() {
            save_file();
        });
    grl->addWidget(but_save, 4, 1, 1, 1);

    QCheckBox* cb = new QCheckBox("График");
    connect(cb, &QCheckBox::stateChanged,
        [&](int i) {
            boolGraf = i;
        });
    grl->addWidget(cb, 3, 2, 1, 2);
}

MainWindow::MainWindow(SamEnum sam, QWidget* parent)
    : QMainWindow(parent)
    , sam(sam)
    , ui(new Ui::MainWindow)
{
    boolGraf = false;
    ui->setupUi(this);

    //    QBrush*brush = new QBrush;
    //    QPalette*palette = new QPalette;
    //    QImage p(":/new/prefix1/su.jpg");
    ////    if (p.height()>height() || p.width()>width())
    ////            p=p.scaled(width(),height(), Qt::KeepAspectRatio);
    //    brush->setTextureImage(p);
    //    setMaximumSize(p.width(), p.height());
    //    setMinimumSize(p.width(), p.height());
    //    palette->setBrush(QPalette::Window, *brush);
    //    this->setPalette(*palette);

    setMaximumSize(width(), height());
    setMinimumSize(width(), height());

    QGridLayout* grl = new QGridLayout();
    ui->centralwidget->setLayout(grl);
    setWindowFlags(Qt::WindowCloseButtonHint);

    switch (sam) {
    case Cy_35:
        Cy_35_(grl);
        break;
    case T_50:
        T_50_(grl);
        break;
    default:
        return;
    }

    setOutElement(grl);

    grl->setRowMinimumHeight(4, 50);

    open_file(QCoreApplication::applicationDirPath() + "/1.cen");
}

MainWindow::~MainWindow()
{
    delete ui;
}

elemMom::elemMom(QStringList sl)
{
    if (sl.size()) {
        name = sl.at(0);
        mass = sl.at(1).toFloat();
        x = sl.at(2).toFloat();
        moment = x * mass;
    } else {
        name = "";
        mass = 0;
        x = 0;
        moment = 0;
    }
}

void elemMom::setMom(float mom)
{
    moment = mom;
}

void elemMom::setMass(float mas)
{
    mass = mas;
    moment = x * mass;
}
