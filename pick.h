#ifndef PICK_H
#define PICK_H
#include "base.h"
#include <QColor>

class Pick : public Base
{
    Q_OBJECT
    Q_PROPERTY(QString pick_name READ getPickName WRITE setPickName)
    Q_PROPERTY(QString color READ getColor WRITE setColor)
    Q_PROPERTY(bool visible READ getVisible WRITE setVisible)
public:
    Pick();
    Pick (const Pick& source);

    Pick &operator = (const Pick& in);

    QString getPickName () const;
    void setPickName (const QString& s);
    QString getColor () const;
    void setColor (const QString& c);
    bool getVisible () const;
    void setVisible (bool v);

private:
    QString _pickName;
    QString _color;
    bool _visible;
};


#endif // PICK_H
