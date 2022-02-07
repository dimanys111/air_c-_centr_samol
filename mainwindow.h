#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qcustomplot.h"
#include <QGridLayout>
#include <QMainWindow>

#include "podves.h"
#include "tochpodves.h"

static const Qt::GlobalColor colors[] = {
    Qt::yellow,
    Qt::gray,
    Qt::lightGray,
    Qt::cyan,
    Qt::magenta,
    Qt::darkCyan,
    Qt::darkMagenta,
    Qt::darkYellow,
    Qt::black,
    Qt::red,
    Qt::darkRed,
    Qt::green,
    Qt::darkGreen,
    Qt::darkGray,
    Qt::blue,
    Qt::darkBlue
};

class TochPodves;

class elemMom {
public:
    elemMom(QStringList sl = QStringList());
    void setMom(float mom);
    void setMass(float mas);
    QString name;
    float mass;
    float x;
    float moment;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(SamEnum sam, QWidget* parent = nullptr);
    ~MainWindow();
    QList<Podves> listPodves;
    SamEnum sam;
public slots:
    void plotMousePress(QMouseEvent* event);
private slots:
    void plottableClick(QCPAbstractPlottable* plottable, int dataIndex, QMouseEvent* event);

protected:
    void closeEvent(QCloseEvent* event);

private:
    QString file_save {};
    QLineEdit* leMass;
    QLineEdit* leCyGp;
    QLineEdit* leXt;
    QLineEdit* leMnes;
    bool boolGraf;
    elemMom momShass;
    QList<elemMom> momSam;
    QList<elemMom> momOrug;
    QList<elemMom> momTopl1;
    QList<elemMom> momTopl2;
    QList<TochPodves*> tochpodv;
    void Cy_35_(QGridLayout* grl);

    void setOutElement(QGridLayout* grl);
    Ui::MainWindow* ui;
    void raschMom();
    void T_50_(QGridLayout* grl);
    void plotGraph(QString& TextPodw, float max_x, QList<QVector<double>>& centrS_y, float min_y, float min_x, QList<QVector<double>>& centrS_x, float max_y);
    void rasMinMax(float& max_y, float& min_x, QList<QVector<double>>& centrS_y, float& min_y, QList<QVector<double>>& centrS_x, float& max_x);
    void rasToplMom(QList<QVector<double>>& centrS_y, float sumMom, float MomPodv, float sumMass, float MassPodv, bool bPodv, QList<QVector<double>>& centrS_x);
    void rasPodv(bool& bPodv, float& MomPodv, float& MassPodv, float& MomZPodv, QString& TextPodw);
    void save_file(QString files = "");
    void open_file(QString files = "");
};

#endif // MAINWINDOW_H
