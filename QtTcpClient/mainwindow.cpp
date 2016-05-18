#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);
  tcpConnect();
  putData();
  getData();
}

void MainWindow::tcpConnect(){
  socket->connectToHost("127.0.0.1",1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
  }
  else{
    qDebug() << "Disconnected";
  }
}

void MainWindow::getData()
{
  QString str;
  QByteArray array;
  QStringList list;
  QDateTime datetime;
  if(socket->state()== QAbstractSocket::ConnectedState){
    socket->write("get 127.0.0.1\r\n");
    socket->waitForBytesWritten(3000);
    socket->waitForReadyRead(3000);
    qDebug() << socket->bytesAvailable();
    while(socket->bytesAvailable()){
      str = socket->readLine().replace("\n","").replace("\r","");
      list = str.split(" ");
      if(list.size() == 2){
        datetime.fromString(list.at(0),Qt::ISODate);
        str = list.at(1);
        qDebug() << datetime << ": " << str;
      }
    }
  }
}

void MainWindow::putData()
{
  QDateTime datetime;
  QString str;
  if(socket->state()== QAbstractSocket::ConnectedState){
    for(int i=0; i<10; i++){
      datetime = QDateTime::currentDateTime();
      str = "set "+
          datetime.toString(Qt::ISODate)+
          " "+
          QString::number(qrand()%35)+"\r\n";

      qDebug() << str;
      socket->write(str.toStdString().c_str());
      socket->waitForBytesWritten(3000);
    }
  }
}
MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}
