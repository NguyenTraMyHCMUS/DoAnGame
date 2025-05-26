#ifndef POINT_H 
#define POINT_H

class Point{
    protected:
        int _x;
        int _y;
        
    public:
        Point();
        Point(int x, int y);

        void setX(int x);
        void setY(int y);
        int getX() const;
        int getY() const;
};

#endif // POINT_H
