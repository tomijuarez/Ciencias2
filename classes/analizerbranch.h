#ifndef ANALIZERBRANCH_H
#define ANALIZERBRANCH_H
#include <QList>
#include <iostream>
#include <string>


class AnalizerBranch
{
public:
    AnalizerBranch(QList<std::string> Branch,bool & close,std::string & formulaOne,std::string & formulaTwo);
    ~AnalizerBranch();
};

#endif // ANALIZERBRANCH_H
