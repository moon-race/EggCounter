#include "object.hpp"

Object::Object(QObject *parent, int val) :
    QObject(parent),
    value_(val)
{

}

const int Object::value()
{
    return value_;
}

void Object::setValue(int val)
{
    if (value_ == val) return;
    value_ = val;
//    qDebug() << "value of" << objectName() << "is changed to" << value_;
    emit valueChanged(value_);
}

void Object::increaseValue()
{
    value_ += 1;
//    qDebug() << "value of" << objectName() << "is changed to" << value_;
    emit valueChanged(value_);
}

void Object::decreaseValue()
{
    if (value_ == 0) return;
    value_ -= 1;
//    qDebug() << "value of" << objectName() << "is changed to" << value_;
    emit valueChanged(value_);
}
