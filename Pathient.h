#ifndef PATHIENT_H
#define PATHIENT_H

#include <QString>

int IDGenerate();

struct Pathient{
    Pathient(const QString& fllNm);

    Pathient(const QString& fllNm, const int& ident);

    Pathient(const Pathient &pathient);

    ~Pathient();

    QString fullName;
    int id;
};

#endif
