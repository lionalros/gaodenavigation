#ifndef WEBCLASS_H
#define WEBCLASS_H

#include <QDebug>
#include <QObject>
#include <QWebEnginePage>

class WebClass : public QObject
{
    Q_OBJECT
public:
    explicit WebClass(QObject *parent = nullptr);

    // cpp端直接通过对象调用
    void sendJsonToWeb(QWebEnginePage* page, const QString& param);

signals:
    void receiveTextFromWeb(float lng,float lat);

    // js端通过注册的对象ID调用
public slots:
    // 必须为槽函数
    void sendTextToCpp(float lng,float lat);





};

#endif // WEBCLASS_H
