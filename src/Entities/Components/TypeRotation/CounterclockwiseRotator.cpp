#include "CounterclockwiseRotator.h"

// CounterclockwiseRotator: Xoay khối Tetromino theo chiều ngược kim đồng hồ
// Phương thức này sẽ xoay các ô của khối Tetromino 4 ô (J, L) ngược chiều kim đồng hồ
void CounterclockwiseRotator::rotate(Point (&blocks)[4]) {
    Point center = blocks[1]; // Điểm trung tâm để xoay
    for (int i = 0; i < 4; i++) {
        int x = blocks[i].getY() - center.getY();
        int y = blocks[i].getX() - center.getX();
        blocks[i].setX(center.getX() + x);
        blocks[i].setY(center.getY() - y);
    }
}
