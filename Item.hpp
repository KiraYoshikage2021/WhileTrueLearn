#ifndef ITEM_HPP
#define ITEM_HPP

class Item {
protected:
    int x, y;
public:
    Item(int c, int r) : x(c), y(r) {}
    virtual ~Item() {}
    int getX() const { return x; }
    int getY() const { return y; }
    void setPos(int c, int r) { x = c; y = r; }
};

#endif

