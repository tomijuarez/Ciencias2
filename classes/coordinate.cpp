#include "coordinate.h"

Coordinate::Coordinate() { }

void Coordinate::setCoord(unsigned int x, unsigned y){
    this->_x = x;
    this->_y = y;
}

unsigned int Coordinate::getCoordX() const{
    return this->_x;
}

unsigned int Coordinate::getCoordY() const{
    return this->_y;
}

Coordinate::~Coordinate()
{

}

