#ifndef PODVES_H
#define PODVES_H

#include <QStringList>

class Podves
{
public:
    QList<QStringList> slTabl;
    Podves &operator<<(QStringList &sl);
    Podves();
    QString Name;
    void setName();
};

#endif // PODVES_H
