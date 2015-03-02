#ifndef DEBUG_H
#define DEBUG_H
#include "treeaux.h"
#include "analizerbranch.h"
#include <QMap>
#include <QQueue>

class Debug
{
public:  
    Debug(TreeAux Tree);
    void StardDebug(QMap<int,QQueue<std::string> > & result);
    //solo pra la veficacion
    void printResult(QMap<int,QQueue<std::string> > result);
    ~Debug();

private:
    TreeAux _Tree;

    struct _oppositeFormulas
    {
        std::string formulaOne;
        std::string formulaTwo;
    };

};

#endif // DEBUG_H
