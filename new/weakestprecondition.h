#ifndef WEAKESTPRECONDITION_H
#define WEAKESTPRECONDITION_H
#include <iostream>
#include <QQueue>
#include <QMap>
#include <string>
#include "parseddata.h"

using namespace std;

class WeakestPreCondition
{
public:
    WeakestPreCondition(ParsedData algorithms,QQueue<string> assertion,unsigned int test);
    void getWp(QQueue<string> & Output);
    ~WeakestPreCondition();

private:
    ParsedData _algorithms;
    QQueue<string> _assertion;
    unsigned int _test;

    void _replacement(string & predicate, string  variable, string expression);

    void _getWp(QMap<string,string> assignations,QQueue<string> assertion,QQueue<string> & Output,bool C);


};

#endif // WEAKESTPRECONDITION_H
