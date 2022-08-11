#include "customqlabel.h"
#include <QDebug>
#include <QMovie>
#include <QTimer>
#include <QDir>
#include <QDateTime>
//CustomQLabel::CustomQLabel()
//{

//}

void CustomQLabel::setImageRelativePath(QString filename)
{
    // /home/root/pic/
#ifdef __WIN32__
    setImagePath("f:/work/Panel_Display/pic/"+filename);
#elif (__ARM_ARCH_7A__)
    setImagePath("/home/root/pic/"+filename);
#elif(__linux__ && __amd64__)
    setImagePath("./pic/"+filename);
#endif
}


CustomQLabel::CustomQLabel(QWidget *parent, Qt::WindowFlags f):QLabel(parent,f)
{
    this->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
    timestop_flag = false;
    timer_state = new QTimer();
    connect(timer_state,SIGNAL(timeout()),this,SLOT(display_zipiamge()));

}

CustomQLabel::CustomQLabel(const QString &text, QWidget *parent, Qt::WindowFlags f):QLabel(text,parent,f)
{

}

CustomQLabel::~CustomQLabel()
{
    if(pixmap!=nullptr)
        delete pixmap;
    if(movie!=nullptr)
        delete movie;
    if(timer_state!=nullptr)
        delete timer_state;
}

void CustomQLabel::display_zip_image(QString filename)
{
//    QString zip_str;
//    zip_str = "unzip -o -d /home/root/pic/zip/ "+filename;
//    system(zip_str.toLatin1().data());
//    zip_str = zip_str.left(zip_str.length()-4);
    //qDebug()<<"setImageRelativePath:"<<filename;
    zipfilename = filename;
    zipimage_count = 0;
    //timer_state->start(20);
    timer_state->start(30);


    QString filename1;
    filename1 = zipfilename+"/"+QString("%1").arg(zipimage_count,4,10,QLatin1Char('0'))+".jpg";
    if(pixmap!=nullptr)
        delete pixmap;
    pixmap = new QPixmap();
    if(!pixmap->load(filename1)){
        delete pixmap;
        pixmap =nullptr;
//        qDebug()<<"display_zipiamge" << filename << "   not fond";
        return;
    }else{
//        qDebug()<<"display_zipiamge" << filename << "   load ok";
    }
    this->setPixmap(*pixmap);
    this->setGeometry(x,y,pixmap->width(),pixmap->height());




}

void CustomQLabel::setImagePath(QString filename)
{
    if(timestop_flag == true)
    {
        imageFileName = filename;
        QDir dir(filename);
        if(dir.exists())
        {

            if(movie!=nullptr){
                movie->stop();
                delete movie;
            }
//            if(timer_state!=nullptr)
//            {
//                timer_state->stop();
//                delete timer_state;
//            }
//            timer_state = new QTimer();
//            connect(timer_state,SIGNAL(timeout()),this,SLOT(display_zipiamge()));
            display_zip_image(filename);
        }
        else if(filename.endsWith(".gif")){
            //gif
            timer_state->stop();
            if(movie!=nullptr){
                movie->stop();
                delete movie;
            }
            movie = new QMovie(filename);
            if(movie->frameCount()<=0){
                //qInfo() << filename << "   load error  " << movie->frameCount();
            }else{
                //qDebug() << filename << "   load ok " << movie->frameCount();
            }
            setMovie(movie);
            movie->start();
            this->setGeometry(x,y,movie->frameRect().width(), movie->frameRect().height());

        }else{
            timer_state->stop();

            if(movie!=nullptr){
                movie->stop();
                setMovie(nullptr);
            }
            // png jpg
            if(pixmap!=nullptr)
                delete pixmap;
            pixmap = new QPixmap();
            if(!pixmap->load(filename)){
                delete pixmap;
                pixmap =nullptr;
                //qDebug() << filename << "   not fond";
                return;
            }else{
                //qDebug() << filename << "   load ok";
            }
            this->setPixmap(*pixmap);
            this->setGeometry(x,y,pixmap->width(),pixmap->height());
        }
    }
    else {

        if(imageFileName != filename){
            imageFileName = filename;
            QDir dir(filename);
            if(dir.exists())
            {

                if(movie!=nullptr){
                    movie->stop();
                    delete movie;
                }
    //            if(timer_state!=nullptr)
    //            {
    //                timer_state->stop();
    //                delete timer_state;
    //            }
    //            timer_state = new QTimer();
    //            connect(timer_state,SIGNAL(timeout()),this,SLOT(display_zipiamge()));
                display_zip_image(filename);
            }
            else if(filename.endsWith(".gif")){
                //gif
                timer_state->stop();
                if(movie!=nullptr){
                    movie->stop();
                    delete movie;
                }
                movie = new QMovie(filename);
                if(movie->frameCount()<=0){
                    //qInfo() << filename << "   load error  " << movie->frameCount();
                }else{
                    //qDebug() << filename << "   load ok " << movie->frameCount();
                }
                setMovie(movie);
                movie->start();
                this->setGeometry(x,y,movie->frameRect().width(), movie->frameRect().height());

            }else{
                timer_state->stop();

                if(movie!=nullptr){
                    movie->stop();
                    setMovie(nullptr);
                }
                // png jpg
                if(pixmap!=nullptr)
                    delete pixmap;
                pixmap = new QPixmap();
                if(!pixmap->load(filename)){
                    delete pixmap;
                    pixmap =nullptr;
                    //qDebug() << filename << "   not fond";
                    return;
                }else{
                    //qDebug() << filename << "   load ok";
                }
                this->setPixmap(*pixmap);
                this->setGeometry(x,y,pixmap->width(),pixmap->height());
            }
        }
    }
}

void CustomQLabel::setX(int value)
{
    x = value;
    this->setGeometry(x,y,this->width(),this->height());
}

void CustomQLabel::setY(int value)
{
    y = value;
    this->setGeometry(x,y,this->width(),this->height());
}

void CustomQLabel::display_zipiamge()
{
    QString filename;
    if(zipimage_count<75)
    {
        zipimage_count++;
    }
    else
    {

        timer_state->stop();
        return;



    }
    filename = zipfilename+"/"+QString("%1").arg(zipimage_count,4,10,QLatin1Char('0'))+".jpg";
    if(pixmap!=nullptr)
        delete pixmap;
    pixmap = new QPixmap();
    if(!pixmap->load(filename)){
        delete pixmap;
        pixmap =nullptr;
        //qDebug()<<"display_zipiamge" << filename << "   not fond";
        return;
    }else{
        //qDebug()<<"display_zipiamge" << filename << "   load ok";
    }
    this->setPixmap(*pixmap);
    this->setGeometry(x,y,pixmap->width(),pixmap->height());

}

void CustomQLabel::settimestopflag(bool flag)
{
    timestop_flag = flag;
}

void CustomQLabel::stoptime()
{
    timer_state->stop();
}
