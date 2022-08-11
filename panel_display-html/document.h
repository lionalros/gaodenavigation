#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <QDebug>
#include <QObject>
#include <QWebEnginePage>

class Document : public QObject
{
    Q_OBJECT

public:
    explicit Document(QObject *parent = nullptr);


    // cpp端直接通过对象调用
    void sendJsonToWeb(QWebEnginePage* page, const QString& param)
    {
        page->runJavaScript(param); //调用函数带字符串类型参数一定需要加双引号
    }

signals:
    void receiveTextFromWeb(const QString &text);

    // js端通过注册的对象ID调用
public slots:
    // 必须为槽函数
    void sendTextToCpp(const QString &text)
    {
        qDebug()<<"******from web*******text="<<text;
        emit receiveTextFromWeb(text);
    }




};

#endif // DOCUMENT_H
