#ifndef PLAYER_H
#define PLAYER_H

#include<main_include.h>

class Player
{
public:
    //
    Player();
    Player(int x_pos ,int y_pos ,int x_blocks ,int y_blocks ,int Step );
    int x_pos;//Position in x radium
    int y_pos;//Position in y radium
    int Step;
    int x_blocks;
    int y_blocks;
    int disL2R;
    int rangeOfFire;
    int HeightOfJump;
    int stepOfShoot;//射击中的第几步
    int stepOfJump;//跳跃中的第几步
    //bool isBacking ;//描述了右半边是否在回来
    bool isShooting ;//描述是否正在发射当中

    bool isJumping;

    bool isIncluded ;


    QRect Area;
    QRect AreaR;



    //Funcion:

    void Move(int dir);//Function for move (dir for Direction )
    void CauculateArea();
    void Paint(QPainter &painter);
    void Shoot();//射击函数
    void setShoot();
    void setJump();
    void Jump();

};

#endif // PLAYER_H
