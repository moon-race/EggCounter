#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>
#include <QMessageBox>
#include "object.hpp"

#define TO_QSTRING QString::fromLocal8Bit

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void setNext();
    void resetCount();

private:
    Ui::Widget *ui;

    Object *accept;
    Object *reject;
    Object *next;
};

#endif // WIDGET_HPP
