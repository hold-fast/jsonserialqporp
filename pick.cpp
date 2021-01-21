#include "pick.h"

Pick::Pick(){

}

Pick::Pick(const Pick &source){
    *this = source;
}

Pick &Pick::operator =(const Pick &in){
    _pickName = in._pickName;
    _color = in._color;
    _visible = in._visible;
    return *this;
}

QString Pick::getPickName() const{
    return _pickName;
}

void Pick::setPickName(const QString &s){
    _pickName = s;
}

QString Pick::getColor() const{
    return _color;
}

void Pick::setColor(const QString &c){
    _color = c;
}

bool Pick::getVisible() const{
    return _visible;
}

void Pick::setVisible(bool v){
    _visible = v;
}
