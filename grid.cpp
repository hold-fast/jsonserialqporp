#include "grid.h"

Grid::Grid(){

}

Grid::~Grid(){

}

Grid::Grid(const Grid &source)
{
    *this = source;
}

Grid &Grid::operator =(const Grid &in){
    _gridName = in._gridName;
    _id = in._id;
    _color = in._color;
    return *this;
}

QString Grid::getGridName() const{
    return _gridName;
}

void Grid::setGridName(const QString &s){
    _gridName = s;
}

long Grid::getId() const{
    return _id;
}

void Grid::setId(long id){
    _id = id;
}

QString Grid::getColor() const{
    return _color;
}

void Grid::setColor(const QString &c){
    _color = c;
}
