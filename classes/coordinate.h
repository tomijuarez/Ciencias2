#ifndef COORDINATE_H
#define COORDINATE_H


class Coordinate
{
public:
    Coordinate();
    void setCoord(unsigned int x,unsigned y);
    unsigned int getCoordX() const;
    unsigned int getCoordY() const;
    ~Coordinate();

private:

    unsigned int _x;
    unsigned int _y;

};

#endif // COORDINATE_H
