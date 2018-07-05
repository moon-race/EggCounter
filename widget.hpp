#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>
#include <QMessageBox>

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

public slots:
    void pushButtonAcceptUpClicked();
    void pushButtonAcceptDownClicked();
    void pushButtonRejectUpClicked();
    void pushButtonRejectDownClicked();
    void resetCount();

private:
    void setNext();
    Ui::Widget *ui;
    int accept;
    int reject;
    int next;
};

#endif // WIDGET_HPP
