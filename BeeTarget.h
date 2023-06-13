//
// Created by Coralie Desquiens on 13/06/2023.
//

#ifndef UNTITLED_BEETARGET_H
#define UNTITLED_BEETARGET_H


class BeeTarget {
protected:
    int x;
    int y;

public:
    BeeTarget();
    BeeTarget(int x, int y);
    ~BeeTarget();
    int getX() const;
    int getY() const;
    virtual bool isHive() const;
    virtual bool isFlower() const;
};


#endif //UNTITLED_BEETARGET_H
