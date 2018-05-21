#include "mw1.h"
#include "ui_mw1.h"

MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    msPerFrame = 500;
    m_timerID=startTimer(50);
    ui->setupUi(this);

     //setWindowFlags(Qt::FramelessWindowHint);
}

MW1::~MW1()
{
    delete ui;
}
void MW1::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
    //qDebug()<<"Got a key";
    if(event->key() == Qt::Key_W||event->key() == Qt::Key_Up)
    {
        pl.Move(0);
    }
    else if(event->key() == Qt::Key_S||event->key() == Qt::Key_Down)
    {
         pl.Move(1);
    }
    else if(event->key() == Qt::Key_A||event->key() == Qt::Key_Left)
    {
        pl.Move(2);
    }
    else if(event->key() == Qt::Key_D||event->key() == Qt::Key_Right)
    {
         pl.Move(3);

     }
    else if(event->key() == Qt::Key_H)
    {
        if(!pl.isShooting)pl.setShoot();
    }

    //update();
}
void MW1::paintEvent(QPaintEvent *event)
{
    setFixedSize((X_NUM+1)*X_Pixels_per,(Y_NUM+2)*Y_Pixels_per);//构建游戏区域

    QPainter painter;
    painter.begin(this);
    pl.Paint(painter);
    this->show();
}
void MW1::timerEvent(QTimerEvent *event)
{
    if (event->timerId()==m_timerID)
    {
       if(pl.isShooting) pl.Shoot();
        update();
    }
}
