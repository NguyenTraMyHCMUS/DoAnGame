#include "StandardRotator.h"

// Xoay thông thường - áp dụng cho đa số các khối (J, L, T, S, Z)
void StandardRotator::rotate(Point (&blocks)[4]) {
    Point center = blocks[1];
    for (int i = 0; i < 4; i++) {
        int x = blocks[i].getY() - center.getY();
        int y = blocks[i].getX() - center.getX();
        blocks[i].setX(center.getX() - x);
        blocks[i].setY(center.getY() + y);
    }
}
