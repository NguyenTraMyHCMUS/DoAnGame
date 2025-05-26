#include "IRotator.h"

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
