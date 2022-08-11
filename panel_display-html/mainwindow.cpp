#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->setWindowFlags(Qt::FramelessWindowHint);
//    ui->widget->setGeometry(0,0,1024,600);
//    ui->widget_2->setGeometry(0,0,1024,600);
//    ui->widget_3->setGeometry(0,0,1024,600);
//    ui->widget->raise();
//    ui->widget_2->raise();
//    ui->widget_3->raise();
//    ui->widget->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
//    ui->widget_2->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
//    ui->widget_3->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
//    Startupform = new startupForm(ui->widget);
//    Startupform->show();
    ui->widget->setVisible(true);
    ui->widget_2->setVisible(false);
    ui->widget_3->setVisible(false);
    ui->widget_4->setVisible(false);
    startup_time = new QTimer(this);
    connect(startup_time, SIGNAL(timeout()), this, SLOT(startup_disp()));
    ui->label_startup->setX(0);
    ui->label_startup->setY(0);
    ui->label_startup->setImageRelativePath("startup");
    ui->btn_startup->setFlat(true);


    engineview = new QWebEngineView(this);
    m_webChannel = new QWebChannel();
    m_webChannel->registerObject(QStringLiteral("jsClass"),&m_document);
    engineview->page()->setWebChannel(m_webChannel);
    ui->boxlayout->addWidget(engineview);
//    engineview->load(QUrl("http://map.baidu.com"));

    QFileInfo filehtml("./map.html");
    engineview->load(QUrl::fromLocalFile(filehtml.absoluteFilePath()));

    startGPS_lon = 116.301934;
    startGPS_lat = 39.977552;

    endGPS_lon = 0.0;
    endGPS_lat = 0.0;


    ui->wid4_faultpic->setVisible(false);
    ui->wid4_faultdisp->setVisible(false);


    connect(&m_document,SIGNAL(receiveTextFromWeb(float,float)),
            this,SLOT(get_html_gpsdata(float,float)));
    ui->start_gps->setText(QString::number(startGPS_lon,'f',6)+","+QString::number(startGPS_lat,'f',6));
    ui->end_gps->setText(QString::number(endGPS_lon,'f',6)+","+QString::number(endGPS_lat,'f',6));
}

MainWindow::~MainWindow()
{
    delete ui;
    startup_time->stop();

}

void MainWindow::startup_disp()
{
    static double gpsLon = 116.457687;
    static double gpsLat = 39.946639;
    QString jsStr1="delMarker("+QString::number(gpsLon)+","+QString::number(gpsLat)+")";
    m_document.sendJsonToWeb(engineview->page(),jsStr1);
    gpsLon += 0.002;
    QString jsStr="addMarker("+QString::number(gpsLon)+","+QString::number(gpsLat)+")";
    //engineview->page()->runJavaScript(jsStr);
    m_document.sendJsonToWeb(engineview->page(),jsStr);

}

void MainWindow::on_btn_startup_clicked()
{
    ui->btn_startup->setVisible(false);
    ui->widget_2->setVisible(true);
    ui->widget->setVisible(false);
}

void MainWindow::on_pushButton_clicked()
{
    ui->widget->setVisible(false);
    ui->widget_2->setVisible(false);
    ui->btn_startup->setVisible(false);
    ui->widget_3->setVisible(true);
    ui->widget_4->setVisible(false);
}



void MainWindow::on_wid4_return_clicked()
{
//    ui->wid3_return->setVisible(true);
//    ui->widget->setVisible(false);
//    ui->widget_2->setVisible(false);
//    ui->btn_startup->setVisible(false);
//    ui->widget_4->setVisible(false);
//    ui->widget_3->setVisible(true);


}

void MainWindow::on_wid3_return_clicked()
{
//    ui->widget_4->setVisible(true);
//    ui->widget->setVisible(false);
//    ui->widget_2->setVisible(false);
//    ui->btn_startup->setVisible(false);
//    ui->widget_3->setVisible(false);
//    ui->wid3_return->setVisible(false);

}

void MainWindow::on_wid3_return_pressed()
{

    ui->widget->setVisible(false);
    ui->widget_2->setVisible(false);
    ui->btn_startup->setVisible(false);
    ui->widget_3->setVisible(false);
    ui->wid3_return->setVisible(false);
    ui->widget_4->setVisible(true);
//    startup_time->start(500);
}

void MainWindow::on_wid4_return_pressed()
{


    ui->widget->setVisible(false);
    ui->widget_2->setVisible(false);
    ui->btn_startup->setVisible(false);
    ui->widget_4->setVisible(false);
    ui->widget_3->setVisible(true);
    ui->wid3_return->setVisible(true);
}

void MainWindow::sendTextToQT(uchar num,QString htmltext)
{
    qDebug()<<"NUM:"<<num<<" html: "<<htmltext;


}

void MainWindow::on_gps_set_clicked()
{
    QString jsStr="addDrivingRoute("+QString::number(startGPS_lon)+","+QString::number(startGPS_lat)\
            +","+QString::number(endGPS_lon)+","+QString::number(endGPS_lat)+")";
    m_document.sendJsonToWeb(engineview->page(),jsStr);
}

void MainWindow::get_html_gpsdata(float lon,float lat)
{
    endGPS_lon = lon;
    endGPS_lat = lat;
    ui->end_gps->setText(QString::number(endGPS_lon,'f',6)+","+QString::number(endGPS_lat,'f',6));

}
