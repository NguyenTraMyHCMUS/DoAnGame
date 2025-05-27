#include "IRotator.h"

// IRotator: Xoay khối Tetromino dạng chữ I
// Phương thức này sẽ xoay các ô của khối I giữa hai trạng thái ngang và dọc
void IRotator::rotate(Point (&blocks)[4]) {
    static bool isHorizontal = true;
    Point center = blocks[1];

    if (isHorizontal) {
        for (int i = 0; i < 4; i++) {
            blocks[i].setX(center.getX());
            blocks[i].setY(center.getY() - 1 + i);
        }
    } 
    else {
        for (int i = 0; i < 4; i++) {
            blocks[i].setX(center.getX() - 1 + i);
            blocks[i].setY(center.getY());
        }
    }

    isHorizontal = !isHorizontal;
}