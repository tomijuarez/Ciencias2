#ifndef DATA_H
#define DATA_H
#include <string>
#include <QString>
class data
{
public:
    data();

    void setData(std::string formula,int x,int y, bool isLiteral){
        this->_formula = formula;
        this->_X = x;
        this->_Y = y;
        this->_isLiteral = isLiteral;
    }

    int getCoordX() const{ return this->_X; }
    int getCoordY() const { return this->_Y;}
    QString getFormula() {
      char output[this->_formula.size()];
      this->_conversion(output,this->_formula);
      QString formula(output);
      return formula;
    }
    bool isLiteral() const { return this->_isLiteral;}
    ~data();

private:

    std::string _formula;
    int _X;
    int _Y;
    bool _isLiteral;

    void _conversion(char output[],std::string input);
};

#endif // DATA_H
