#pragma once

#include <QtWidgets/QWidget>
#include "ui_kalaOKServer.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QJsonObject>
#include <QSqlDatabase>
#include <QtSql>

class kalaOKServer : public QWidget
{
    Q_OBJECT

public:
    kalaOKServer(QWidget *parent = Q_NULLPTR);

private:
    Ui::kalaOKServerClass ui;
	QTcpServer *server;
	QTcpSocket *socket = 0;
	char buffer[2048];
	QJsonObject receiveJson;
	QSqlDatabase db;

	void init();
	void initDatabase();
	void sendMessage(QJsonObject json);
	void responseOrder();
	void responseHotMusic();
	void responSesearch();

private slots:
	void ServerNewConnection();
	void ServerReadData();
	void on_btn_exec_clicked();
};
