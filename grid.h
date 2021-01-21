#ifndef GRID_H
#define GRID_H
#include "base.h"
#include <QColor>

class Grid : public Base
{
    Q_OBJECT
    Q_PROPERTY(QString grid_name READ getGridName WRITE setGridName)
    Q_PROPERTY(long id READ getId WRITE setId)
    Q_PROPERTY(QString color READ getColor WRITE setColor)

public:
    Grid();
    virtual ~Grid();

    Grid (const Grid& source);

    Grid &operator = (const Grid& in);

    QString getGridName() const;
    void setGridName(const QString& s);
    long getId() const;
    void setId(long id);
    QString getColor() const;
    void setColor(const QString& c);


private:
    QString _gridName;
    long _id;
    QString _color;
};


#endif // GRID_H
