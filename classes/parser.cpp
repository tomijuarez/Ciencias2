#include "parser.h"
#include "lex.yy.c"

typedef yy_buffer_state *YY_BUFFER_STATE;
extern int yyparse();
extern YY_BUFFER_STATE yy_scan_string(char *, size_t);

Parser::Parser() { }

Parser::~Parser() { }

void Parser::_cleanParserData() {
    ifFound = false;
    elseFound = false;
    whileFound = false;
    assignationsFalse.clear();
    assignationsTrue.clear();
    outsideAssignations.clear();
    tree.clear();
}

void Parser::getData(QQueue<string> & data) {
    tree.toQueue(data);
    tree.clear();
}

void Parser::getAlgorithmData(ParsedData & data) {
    QQueue<string> tokens;
    tree.toQueue(tokens);

    data.setData(
                    ifFound,
                    elseFound,
                    whileFound,
                    assignationsTrue,
                    assignationsFalse,
                    outsideAssignations,
                    tokens
                );

    this->_cleanParserData();
}


void Parser::parse(char condition[]) {
    strcat(condition, "\0\0");
    yy_scan_string(condition);
    yyparse();
}

void Parser::parse(QString condition) {
    QByteArray array = condition.toLocal8Bit();
    char* buffer = array.data();
    this->parse(buffer);
}


