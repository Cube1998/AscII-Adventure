#ifndef MW1_H
#define MW1_H

#include <QMainWindow>
#include "player.h"
#include "main_include.h"
namespace Ui {
class MW1;

}

class MW1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MW1(QWidget *parent = 0);
    ~MW1();
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

    Player pl;
private:
    Ui::MW1 *ui;
    int msPerFrame;
    int m_timerID;


};

#endif // MW1_H
