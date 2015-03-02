#ifndef PARSEDDATA_H
#define PARSEDDATA_H

#include <QMap>
#include <string>
#include <QQueue>

class ParsedData
{
public:
    ParsedData() { };
    ~ParsedData() { };

    void setData( bool isIf, bool elseFound, bool isWhile,
                QMap<std::string, std::string> assignationsTrue,
                QMap<std::string, std::string> assignationsFalse,
                QMap<std::string, std::string> assignationsOutside,
                QQueue<std::string> conditionsTokens
                ) {
        this->_isIf = isIf;
        this->_elseFound = elseFound;
        this->_isWhile = isWhile;
        this->_assignationsTrue = assignationsTrue;
        this->_assignationsFalse = assignationsFalse;
        this->_assignationsOutside = assignationsOutside;
        this->_conditionTokens = conditionsTokens;
    }

    bool isIf()const { return this->_isIf; }
    bool elseFound()const { return this->_elseFound; }
    bool isWhile() const { return this->_isWhile; }
    void getConditionTokens(QQueue<std::string> & conditionTokens) { conditionTokens = this->_conditionTokens; }
    void getOutsideAssignations(QMap<std::string, std::string> & assignations) { assignations = this->_assignationsOutside; }
    void getAssignationsTrue(QMap<std::string, std::string> & assignations) { assignations = this->_assignationsTrue; }
    void getElseAssignations(QMap<std::string, std::string> & assignations) { assignations = this->_assignationsFalse; }

private:
    bool _isWhile;
    bool _isIf;
    bool _elseFound;
    QMap<std::string, std::string> _assignationsTrue;
    QMap<std::string, std::string> _assignationsFalse;
    QMap<std::string, std::string> _assignationsOutside;
    QQueue<std::string> _conditionTokens;
};

#endif // PARSEDDATA_H
