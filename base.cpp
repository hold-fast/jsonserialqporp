#include "base.h"
#include <QMetaProperty>
#include <QJsonObject>

Base::Base(QObject *parent) : QObject(parent){

}

Base::~Base(){

}


void Base::toJson (QJsonDocument& doc){
    QJsonObject obj;
    const QMetaObject *metaobject = metaObject();
    int count = metaobject->propertyCount();
    int offset = metaObject()->propertyOffset();
    for (int i=offset; i < count; ++i) {
        QMetaProperty metaproperty = metaobject->property(i);
        const char *name = metaproperty.name();
        QVariant value = property(name);
        QJsonValue jsonVal = QJsonValue::fromVariant (value);
        obj.insert(name, jsonVal);
    }

    doc.setObject(obj);
}
void Base::fromJson (const QJsonDocument& doc){
    QJsonObject jsonObj = doc.object();
    fromJsonObj(jsonObj);
}

void Base::fromJsonObj(QJsonObject &jsonObj){
    const QMetaObject *metaobject = metaObject();
    int count = metaobject->propertyCount();
    for (int i=0; i < count; ++i) {
        QMetaProperty metaproperty = metaobject->property(i);
        const char *name = metaproperty.name();
        if(jsonObj.contains(name))
        {
            QJsonValue val = jsonObj.take(name);
            if(val.isObject()){
                setProperty(name, val.toObject());
            } else {
                setProperty(name, val);
            }
        }
    }
}
