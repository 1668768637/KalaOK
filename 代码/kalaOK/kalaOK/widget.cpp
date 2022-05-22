#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonArray>
#include <QByteArray>
#include <QString>
#include <QPushButton>
#include <QLayout>
#include <QFile>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::hotMusicInfoChanged()
{
    QJsonArray musicnames = receiverJson.value("musicNames").toArray();
    QJsonArray singers = receiverJson.value("singers").toArray();
    QString string = "热歌榜：\n";
    for(int i = 0;i < 10;i++)
    {
        string += musicnames[i].toString()+"--"+singers[i].toString()+"\n";
    }
    ui->labelHotMusic->setText(string);
}

void Widget::orderMusicInfoChanged()
{
    //清空所有点歌按钮
    QLayoutItem *child;
    while((child = ui->musicListLayout->takeAt(0)) != 0)
    {
        if(child->widget())
        {
            child->widget()->setParent(NULL);
        }
        delete child;
    }
    QJsonArray musicnames = receiverJson.value("musicNames").toArray();
    QJsonArray singers = receiverJson.value("singers").toArray();
    qDebug()<<"长度"<<singers.size();
    QString string;
    //重新添加点歌按钮
    for(int i = 0;i < receiverJson.value("singers").toArray().size();i++)
    {
        string = musicnames[i].toString()+"-"+singers[i].toString();
        QPushButton* button = new QPushButton(string);
        button->setStyleSheet("QPushButton{background-color:rgb(255, 34, 49,0);color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"
                              "\nQPushButton:hover{background-color:rgb(0, 0, 0,100); color: black;}\nQPushButton:pressed{background-color:rgb(132, 158, 162); border-style: inset;"
                              " font:\"古风隶书字体\" }");
        QFont font("古风隶书字体");
        font.setPointSize(25);
        button->setFont(font);
        connect(button,SIGNAL(clicked()),this,SLOT(orderMusic()));
        ui->musicListLayout->addWidget(button);
    }
}

void Widget::init()
{
    setWindowTitle("厚里蟹卡拉OK系统");
    netState = false;
    ui->hotMusicGroup->hide();
    ui->musicHisroyGroup->hide();
    ui->orderMusicGroup->hide();
    ui->setGroup->hide();

    //链接服务器
    connectToServer();

    //加载历史文件
    QFile file("../file/history.txt");
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream in(&file);
        in.setCodec("UTF-8");
        while (!in.atEnd())
        {
            history.append(in.readLine());      //整行读取
        }
        file.close();
    }
    else
        qDebug()<<"文件打开失败";
}

void Widget::on_btnHistory_clicked()
{
    ui->mainGroup->hide();
    QString str = "点歌记录：\n";
    for(int i = 0;i < history.length();i++)
    {
        str +=( history[i] + "\n");
    }
    ui->labelHistory->setText(str);
    ui->musicHisroyGroup->show();
}

void Widget::on_btnHotMusic_clicked()
{
    ui->mainGroup->hide();
    QJsonObject json;
    json.insert("questType","hotMusic");
    sendMessage(json);
    ui->hotMusicGroup->show();
}

void Widget::on_btnOrderMusic_clicked()
{
    ui->mainGroup->hide();
    ui->orderMusicGroup->show();
}

void Widget::on_btnSearch_clicked()
{
    QJsonObject json;
    json.insert("questType","search");
    json.insert("musicName",ui->editMusicInfo->text());
    sendMessage(json);
    qDebug()<<"发送成功";
}

void Widget::on_btn_hotMusicBack_clicked()
{
    ui->hotMusicGroup->hide();
    ui->mainGroup->show();
}

void Widget::on_btn_musHisBack_clicked()
{
    ui->musicHisroyGroup->hide();
    ui->mainGroup->show();
}

void Widget::on_btn_orderBack_clicked()
{
    ui->orderMusicGroup->hide();
    ui->mainGroup->show();
}

void Widget::on_btnSet_clicked()
{
    ui->setGroup->show();
}

void Widget::on_btn_setClose_clicked()
{
    ui->setGroup->hide();
}

void Widget::on_btnRefreshNetwork_clicked()
{
    connectToServer();
}

void Widget::orderStateChange()
{
    if(receiverJson.value("result").toInt())
    {
        QMessageBox::information(this, "点歌结果", "点歌成功！");
        if(!history.contains(receiverJson.value("music").toString()))
            history.append(receiverJson.value("music").toString());

        //写入历史记录文件
        QFile file("../file/history.txt");
        file.remove();
        if(file.open(QIODevice::ReadWrite))
        {
            for(int i = 0;i < history.length();i++)
            {

                file.write(history[i].toUtf8());
                file.write("\n");
            }
        }
        else
        {
            qDebug()<<"文件打开失败";
        }
    }
    else
        QMessageBox::information(this, "点歌结果", "点歌失败！");
}

void Widget::orderMusic()
{
    QJsonObject json;
    json.insert("questType","order");
    json.insert("musicName",((QPushButton*)sender())->text());
    sendMessage(json);



}

void Widget::sendMessage(QJsonObject& json)
{
    QJsonDocument document;
    document.setObject(json);
    clientSocket->write(document.toJson(QJsonDocument::Compact));
}

void Widget::connectToServer()
{
    clientSocket = new QTcpSocket();
    clientSocket->connectToHost(ui->editIP->text(),ui->editPort->text().toInt());
    if(!clientSocket->waitForConnected(300))
    {
        QMessageBox::information(this, "QT网络通信", "连接服务端失败！");
        ui->networkState->setText("未链接");
    }
    else
    {
        QMessageBox::information(this, "QT网络通信", "连接服务端成功！");
        netState = true;
        ui->networkState->setText("已链接");
        connect(clientSocket, SIGNAL(readyRead()), this, SLOT(ClientRecvData()));
    }
}

void Widget::ClientRecvData()
{
    QByteArray ba = clientSocket->readAll();
    QJsonDocument document = QJsonDocument::fromJson(ba);
    receiverJson = document.object();
    qDebug()<<"receivetype|"<<receiverJson.value("responseType").toString();
    if(receiverJson.value("responseType").toString() == "search")orderMusicInfoChanged();
    if(receiverJson.value("responseType").toString() == "hotMusic")hotMusicInfoChanged();
    if(receiverJson.value("responseType").toString() == "order")orderStateChange();
}

