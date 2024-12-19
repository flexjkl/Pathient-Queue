#ifndef PATHIENT_H
#define PATHIENT_H

#include <QString>

int IDGenerate();

struct Pathient{
    Pathient(const QString& fllNm);

    ~Pathient();

    int id;
    QString fullName;
};

#endif
