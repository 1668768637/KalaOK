#include "kalaOKServer.h"

#include <QTcpServer>
#include <QMessageBox>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QJsonObject>
#include <QNetworkProxyFactory>
#include <QDebug>
#include <QSqlQuery>

kalaOKServer::kalaOKServer(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	setWindowTitle(u8"厚里蟹卡拉OK点歌系统服务端");
	init();
}

void kalaOKServer::init()
{
	server = new QTcpServer();
	QNetworkProxyFactory::setUseSystemConfiguration(false);

	if (!server->listen(QHostAddress::Any, 9999))
	{
		qDebug() << "服务器端监听失败！++" + server->errorString();
	}
	else
	{
		connect(server, SIGNAL(newConnection()), this, SLOT(ServerNewConnection()));
		QMessageBox::information(this, u8"QT网络通信", u8"服务器端监听成功！");
		initDatabase();
	}
}

void kalaOKServer::initDatabase()
{
	db = QSqlDatabase::addDatabase("QMYSQL");//加入MySQL数据库
	db.setHostName("127.0.0.1");//本机ip
	db.setPort(3306);
	db.setDatabaseName("ruanjian");//数据库名称
	db.setUserName("root");
	db.setPassword("123456");
	//打开数据库
	if (db.open() == false)
	{
		ui.serverInfo->append(db.lastError().text() + '\n');//链接失败
	}
	else
	{
		ui.serverInfo->append(u8"链接数据库成功\n");//链接成功
	}
}

void kalaOKServer::sendMessage(QJsonObject json)
{
	QJsonDocument document;
	document.setObject(json);
	socket->write(document.toJson(QJsonDocument::Compact));
}

void kalaOKServer::responseOrder()
{
	QString musicName = receiveJson.value("musicName").toString().split('-').first();
	QSqlQuery query;
	if (query.exec(u8"update song set browseNums = browseNums+1 where song = \"" + musicName + "\";"))
	{
		ui.serverInfo->append(u8"点歌成功\n");
		QJsonObject json;
		json.insert("responseType", "order");
		json.insert("result", 1);
		json.insert("music", musicName);
		sendMessage(json);
	}
	else
	{
		ui.serverInfo->append(query.lastError().text() + u8"，点歌失败");
	}
	
}

void kalaOKServer::responseHotMusic()
{
	QSqlQuery query;
	if (query.exec(u8"SELECT song,singer,browseNums from song ORDER BY  browseNums  DESC LIMIT 0, 10;"))
	{
		QJsonArray hotMusics,singers;
		QJsonObject json;
		while (query.next())
		{
			hotMusics.append(query.value(0).toString());
			singers.append(query.value(1).toString());
		}
		json.insert("responseType", "hotMusic");
		json.insert("musicNames", singers);
		json.insert("singers", hotMusics);
		sendMessage(json);
		ui.serverInfo->append(u8"热歌榜发送成功\n");
	}
	else
	{
		ui.serverInfo->append(query.lastError().text() + u8"热歌榜发送失败\n");
	}
}

void kalaOKServer::responSesearch()
{
	QSqlQuery query = QSqlQuery(db);
	QString str = "select singer,song from song where song = \"" + receiveJson.value("musicName").toString() + "\""
					" or singer = \"" + receiveJson.value("musicName").toString() + "\";";
	QJsonArray Singer, Song;
	if (query.exec(str))
	{
		ui.serverInfo->append(u8"回复查询成功");
		while (query.next())
		{
			Singer.append(query.value(0).toString());
			ui.serverInfo->append(query.value(0).toString());
			Song.append(query.value(1).toString());
			ui.serverInfo->append(query.value(1).toString());
		}
		QJsonObject json;
		json.insert("responseType", "search");
		json.insert("musicNames", Song);
		json.insert("singers", Singer);
		sendMessage(json);//发送响应
	}
	else
	{
		ui.serverInfo->append(query.lastError().text() + u8"查询失败");
	}
}

void kalaOKServer::ServerNewConnection()
{
	socket = server->nextPendingConnection();
	ui.serverInfo->append(u8"新建链接：" + socket->peerAddress().toString());
	connect(socket, SIGNAL(readyRead()), this, SLOT(ServerReadData()));
}

void kalaOKServer::ServerReadData()
{
	QByteArray ba = socket->readAll();
	QJsonDocument document = QJsonDocument::fromJson(ba);
	receiveJson = document.object();
	receiveJson = document.object();
	ui.serverInfo->append(u8"收到请求" + receiveJson.value("questType").toString());
	if (receiveJson.value("questType").toString() == "order")responseOrder();
	if (receiveJson.value("questType").toString() == "hotMusic")responseHotMusic();
	if (receiveJson.value("questType").toString() == "search")responSesearch();
}

void kalaOKServer::on_btn_exec_clicked()
{
	QSqlQuery query;
	if (query.exec(ui.sqlString->text()))
		ui.serverInfo->append(u8"执行成功");
	else
		ui.serverInfo->append(u8"执行失败");
}
