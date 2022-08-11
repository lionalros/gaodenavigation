#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QHBoxLayout>
#include <QFileInfo>
#include <QWebEngineView>
#include <QWebChannel>
#include <QWebEngineProfile>
#include "startupform.h"
#include "webclass.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    startupForm *Startupform = nullptr;
    QTimer *startup_time;


    QWebEngineView *engineview;
    QWebChannel *m_webChannel;
    WebClass m_document;
    float startGPS_lon;
    float startGPS_lat;

    float endGPS_lon;
    float endGPS_lat;

private slots:
    void startup_disp();
    void on_btn_startup_clicked();
    void on_pushButton_clicked();
    void on_wid4_return_clicked();
    void on_wid3_return_clicked();
    void on_wid3_return_pressed();
    void on_wid4_return_pressed();

    void sendTextToQT(uchar num,QString htmltext);
    void on_gps_set_clicked();

    void get_html_gpsdata(float lon,float lat);
};
#endif // MAINWINDOW_H
