#include "webclass.h"

WebClass::WebClass(QObject *parent) : QObject(parent)
{

}
void WebClass::sendTextToCpp(float lng,float lat)
{
    qDebug()<<"******from web**"<<QString::number(lng)<<","<<QString::number(lat);
    emit receiveTextFromWeb(lng,lat);
}
void WebClass::sendJsonToWeb(QWebEnginePage* page, const QString& param)
{
    page->runJavaScript(param); //调用函数带字符串类型参数一定需要加双引号
}
