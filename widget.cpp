#include "widget.hpp"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    accept(new Object(this)),
    reject(new Object(this)),
    next(new Object(this, 1))
{
    ui->setupUi(this);

    connect(ui->pushButtonAcceptUp, SIGNAL(clicked()),
            accept, SLOT(increaseValue()));
    connect(ui->pushButtonAcceptDown, SIGNAL(clicked()),
            accept, SLOT(decreaseValue()));
    connect(ui->pushButtonRejectUp, SIGNAL(clicked()),
            reject, SLOT(increaseValue()));
    connect(ui->pushButtonRejectDown, SIGNAL(clicked()),
            reject, SLOT(decreaseValue()));
    connect(ui->pushButtonRecet, SIGNAL(clicked()),
            this, SLOT(resetCount()));

    connect(accept, SIGNAL(valueChanged(int)),
            this, SLOT(setNext()));
    connect(reject, SIGNAL(valueChanged(int)),
            this, SLOT(setNext()));

    connect(accept, SIGNAL(valueChanged(int)),
            ui->lcdNumberAccept, SLOT(display(int)));
    connect(reject, SIGNAL(valueChanged(int)),
            ui->lcdNumberReject, SLOT(display(int)));
    connect(next, SIGNAL(valueChanged(int)),
            ui->lcdNumberNext, SLOT(display(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resetCount()
{
    int reply = QMessageBox::question(this,
                                      TO_QSTRING("確認"),
                                      TO_QSTRING("本当にリセットしますか？"),
                                      QMessageBox::Yes | QMessageBox::No,
                                      QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        accept->setValue(0);
        reject->setValue(0);
    }
}

void Widget::setNext()
{
    next->setValue(accept->value() + reject->value() + 1);
}
