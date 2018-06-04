#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <QObject>
#include <QDebug>

class Object : public QObject
{
    Q_OBJECT
public:
    explicit Object(QObject *parent = nullptr, int val = 0);

    const int value();

signals:
    void valueChanged(int);

public slots:
    void setValue(int);
    void increaseValue();
    void decreaseValue();

private:
    int value_;
};

#endif // OBJECT_HPP
