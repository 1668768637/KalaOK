#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonObject>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QTcpSocket *clientSocket;
    char buffer[2048];
    bool netState;

    QList<QString> history;
    QJsonObject receiverJson;


    void hotMusicInfoChanged();
    void orderMusicInfoChanged();
    void orderStateChange();
    void init();
    void sendMessage(QJsonObject& json);
    void connectToServer();

private slots:
    void on_btnHistory_clicked();
    void on_btnHotMusic_clicked();
    void on_btnOrderMusic_clicked();
    void on_btnSearch_clicked();
    void on_btn_hotMusicBack_clicked();
    void on_btn_musHisBack_clicked();
    void on_btn_orderBack_clicked();
    void on_btnSet_clicked();
    void on_btn_setClose_clicked();
    void on_btnRefreshNetwork_clicked();


    void orderMusic();

    void ClientRecvData();

};

#endif // WIDGET_H
