#ifndef REFUTATIONTREEPARSER_H
#define REFUTATIONTREEPARSER_H

#include "parser.h"
#include <iostream>
#include <string>

using namespace std;

class RefutationTreeParser: public Parser {
    public:
        RefutationTreeParser(string algorithm, string precondition, string postcondition, string invariant, string bound);
        ~RefutationTreeParser();
};

#endif // REFUTATIONTREEPARSER_H
