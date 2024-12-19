#include "Pathient.h"
#include <ctime>

int IDGenerate(){
    std::srand(time(nullptr));
    int genID = (clock() - rand()) % 100000;
    if(genID < 0) return genID*(-1);
    return genID;
}

Pathient::Pathient(const QString& fllNm) : fullName(fllNm), id(IDGenerate()) {}

Pathient::~Pathient() {}
