#ifndef INTERPLIST_H
#define INTERPLIST_H
#include <QObject>
#include "grid.h"
#include "pick.h"

class InterpList : public Base
{
    Q_OBJECT

    Q_PROPERTY(QJsonObject grid /*READ getGridObj*/ WRITE setGridObj)
    Q_PROPERTY(QJsonObject pick /*READ getPickObj*/ WRITE setPickObj)

public:
    InterpList();
    virtual ~InterpList();

    //QJsonObject getGridObj () const;
    void setGridObj (QJsonObject& g);
    //QJsonObject getPickObj () const;
    void setPickObj (QJsonObject& p);


    Grid getGrid () const;
    void setGrid (const Grid& g);
    Pick getPick () const;
    void setPick (const Pick& p);

private:
    Grid _grid;
    Pick _pick;
};

#endif // INTERPLIST_H
