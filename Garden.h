//
// Created by Max on 11/06/2023.
//

#include <vector>
#include "Hive.h"

#ifndef UNTITLED_GARDEN_H
#define UNTITLED_GARDEN_H


class Garden {
private:

    int mapSize;
    int maxHives;
    int actualHives;
    int flowerCount;
    vector<Hive*> hives;

public:
    // constructor
    Garden(int maxHives, int mapSize);
    // destructor
    ~Garden();
    // print
    void print();
    // add hive
    bool addHive(Hive *hive);
    // make it full
    void addHives(int hiveCount, int beeCapacity);
    // Make hives full
    void makeHivesFull();

    // draw
    void draw(sf::RenderWindow &window);
    // update
    void update();
};


#endif //UNTITLED_GARDEN_H
