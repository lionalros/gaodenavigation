#ifndef CUSTOMQLABEL_H
#define CUSTOMQLABEL_H
#include <QLabel>

class CustomQLabel : public QLabel
{
    Q_OBJECT
public:
    //    CustomQLabel();
    explicit CustomQLabel(QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    explicit CustomQLabel(const QString &text, QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    ~CustomQLabel();
    //    explicit CustomQLabel(QWidget *parent=nullptr);
    //    explicit CustomQLabel(const QString &text, QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    void setImagePath(QString filename);
    void setImageRelativePath(QString filename);
    void setX(int value);
    void setY(int value);
    void settimestopflag(bool flag);
    void stoptime();

private:
    QPixmap *pixmap=nullptr;
    QMovie *movie=nullptr;
    QString imageFileName;
    QString zipfilename;
    QTimer *timer_state=nullptr;
    int x;
    int y;
    void display_zip_image(QString filename);
    int zipimage_count;
    bool timestop_flag;

private slots:
    void display_zipiamge();

signals:
    void __displaycar();
};

#endif // CUSTOMQLABEL_H
