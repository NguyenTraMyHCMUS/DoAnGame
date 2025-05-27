#include "StandardRotator.h"

// StandardRotator: Xoay khối Tetromino theo chiều xoay chuẩn
// Phương thức này sẽ xoay các ô của khối Tetromino 4 ô (T, S, Z)
void StandardRotator::rotate(Point (&blocks)[4]) {
    Point center = blocks[1];
    for (int i = 0; i < 4; i++) {
        int x = blocks[i].getY() - center.getY();
        int y = blocks[i].getX() - center.getX();
        blocks[i].setX(center.getX() - x);
        blocks[i].setY(center.getY() + y);
    }
}
