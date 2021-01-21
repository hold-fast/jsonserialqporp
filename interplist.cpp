#include "interplist.h"

InterpList::InterpList(){

}

InterpList::~InterpList(){

}

/*QJsonObject InterpList::getGridObj() const{
    QJsonDocument doc;
    _grid.toJson(doc);
    return doc.object();
}*/

void InterpList::setGridObj(QJsonObject &g)
{
    _grid.fromJsonObj(g);
}

/*QJsonObject InterpList::getPickObj() const{
    QJsonDocument doc;
    _pick.toJson(doc);
    return doc.object();
}*/

void InterpList::setPickObj(QJsonObject &p)
{
    _pick.fromJsonObj(p);
}

Grid InterpList::getGrid() const{
    return _grid;
}

void InterpList::setGrid(const Grid &g){
    _grid = g;
}

Pick InterpList::getPick() const{
    return _pick;
}

void InterpList::setPick(const Pick &p){
    _pick = p;
}
