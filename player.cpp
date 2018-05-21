#include "player.h"

Player::Player()
{

    this->x_pos = 1;
    this->y_pos = 1;
    this->x_blocks = 1;
    this->y_blocks = 2;
    this->Step = 1;
    this->disL2R = 0;
    this->rangeOfFire = 7;
    this->stepOfAction = 0;
   // this->isBacking = false;
   // this->isGoing = true;
    this->isIncluded = false;
    this->isShooting = false;
    this->CauculateArea();


}

void Player::CauculateArea()
{
    Area.setRect(x_pos*X_Pixels_per,y_pos*Y_Pixels_per,x_blocks*X_Pixels_per,y_blocks*Y_Pixels_per);
    AreaR.setRect(Area.right()+(disL2R)*X_Pixels_per,Area.top(),x_blocks*X_Pixels_per,y_blocks*Y_Pixels_per);

}

Player::Player(int x_pos ,int y_pos ,int x_blocks ,int y_blocks,int Step )
{
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->x_blocks = x_blocks;
    this->y_blocks = y_blocks;
    this->Step = Step;
    this->CauculateArea();

}

void Player::Move(int dir)
{
    int x[4] = {0,0,-1,1}, y[4] = {-1,1,0,0};
    dir = dir%4;
    int tmp_x = this->x_pos + x[dir]*Step;
    int tmp_y = this->y_pos + y[dir]*Step;
    if(tmp_x>=0&&tmp_y>=0&& tmp_x<X_NUM&&tmp_y<Y_NUM)
    {
    this->x_pos += x[dir]*Step;
    this->y_pos += y[dir]*Step;
    }
    this->CauculateArea();
}
void Player::Paint(QPainter &painter)
{
   // painter.setBrush(Qt::black);
   // painter.begin(this);
   // painter.begin(QPaintDevice );
    painter.setPen(QPen(Qt::black));
    painter.drawImage(this->Area,QImage("/Users/cube.z/Qt Coding/AscII/2.png"),QRect(0,0,32,64));
    painter.drawImage(this->AreaR,QImage("/Users/cube.z/Qt Coding/AscII/2.png"),QRect(0,0,32,64));
    //painter.drawRect(this->Area);
    //painter.drawRect(this->AreaR);
   // painter.end(this);
    qDebug()<<this->isShooting<<this->disL2R<<this->stepOfAction;

}
void Player::setShoot()
{
    isShooting = !isShooting;
}
void Player::Shoot()
{
    if(stepOfAction<rangeOfFire){stepOfAction++;disL2R++;this->CauculateArea();}
    else{stepOfAction++;disL2R--;this->CauculateArea();}
    if(stepOfAction==2*rangeOfFire){stepOfAction = 0;setShoot();}

}
