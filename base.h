#ifndef BASE_H
#define BASE_H

#include <QObject>
#include <QJsonDocument>

class Base : public QObject
{
    Q_OBJECT
public:
    explicit Base(QObject *parent = nullptr);
    virtual ~Base();

    virtual void toJson (QJsonDocument &doc);
    virtual void fromJson (const QJsonDocument& doc);
    virtual void fromJsonObj (QJsonObject& jsonObj);

signals:

};

#endif // BASE_H
