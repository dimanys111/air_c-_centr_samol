#include "podves.h"

Podves &Podves::operator<<(QStringList &sl)
{
    slTabl<<sl;
}

Podves::Podves()
{

}

void Podves::setName()
{
    Name=slTabl.at(0).at(1);
}
