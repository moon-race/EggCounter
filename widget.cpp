#include "widget.hpp"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    accept(0),
    reject(0),
    next(1)
{
    ui->setupUi(this);

    connect(ui->pushButtonAcceptUp, SIGNAL(clicked()),
            this, SLOT(pushButtonAcceptUpClicked()));
    connect(ui->pushButtonAcceptDown, SIGNAL(clicked()),
            this, SLOT(pushButtonAcceptDownClicked()));
    connect(ui->pushButtonRejectUp, SIGNAL(clicked()),
            this, SLOT(pushButtonRejectUpClicked()));
    connect(ui->pushButtonRejectDown, SIGNAL(clicked()),
            this, SLOT(pushButtonRejectDownClicked()));
    connect(ui->pushButtonRecet, SIGNAL(clicked()),
            this, SLOT(resetCount()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::pushButtonAcceptUpClicked()
{
    accept++;
    ui->lcdNumberAccept->display(accept);
    setNext();
    ui->lcdNumberNext->display(next);
}

void Widget::pushButtonAcceptDownClicked()
{
    if (accept > 0)
    {
        accept--;
        ui->lcdNumberAccept->display(accept);
        setNext();
        ui->lcdNumberNext->display(next);
    }
}

void Widget::pushButtonRejectUpClicked()
{
    reject++;
    ui->lcdNumberReject->display(reject);
    setNext();
    ui->lcdNumberNext->display(next);
}

void Widget::pushButtonRejectDownClicked()
{
    if (reject > 0)
    {
        reject--;
        ui->lcdNumberReject->display(reject);
        setNext();
        ui->lcdNumberNext->display(next);
    }
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
        accept = 0;
        reject = 0;
        setNext();
        ui->lcdNumberAccept->display(accept);
        ui->lcdNumberReject->display(reject);
        ui->lcdNumberNext->display(next);
    }
}

void Widget::setNext()
{
    next = accept + reject + 1;
}
