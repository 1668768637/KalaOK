#include "ordermusic.h"
#include "ui_ordermusic.h"

OrderMusic::OrderMusic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderMusic)
{
    ui->setupUi(this);
    setWindowTitle("厚里蟹卡拉OK系统");
}

OrderMusic::~OrderMusic()
{
    delete ui;
}

void OrderMusic::receive_widget_toOrderMusic()
{
    this->show();
}

void OrderMusic::on_btnBack_clicked()
{
    this->hide();
    emit show_widget();
}
