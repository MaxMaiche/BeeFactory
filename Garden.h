//
// Created by Max on 11/06/2023.
//

#include <vector>
#include "Hive.h"
#include "Flower.h"

#ifndef UNTITLED_GARDEN_H
#define UNTITLED_GARDEN_H


class Garden {
private:

    int mapSize;
    int maxHives;

    vector<Hive*> hives;
    vector<Flower*> flowers;

    //per tick lists to speed up
    vector<Bee*> beesThatNeedNewFlower;
    vector<Flower*> deadFlowers;
    vector<Flower*> newFlowers;


public:
    // constructor
    Garden(int maxHives, int mapSize);
    // destructor
    ~Garden();
    // getHives
    vector<Hive*> & getHives();
    // print
    void print();
    // add hive
    bool addHive(Hive *hive);
    // make it full
    void addHives(int hiveCount, int beeCapacity);
    // Make hives full
    void makeHivesFull();
    // add flower
    void addFlower(Flower *flower);
    // add flowers
    void addFlowers(int nbFlower, int flowerScore);

    // draw
    void draw(sf::RenderWindow &window) const;
    Flower* getRandomFlower();


    // Calculate nearest flower for each hive
    void calculateNearestFlowerForHives();
    // Make one bee follow nearest flower
    void makeOneBeeFollowNearestFlower(Bee* bee);
    // Make bees follow nearest flower
    void makeBeesFollowNearestFlower();

    // Check Bee on flower or Hive
    void checkBeesOnFlowerOrHive();
    // updateposition
    void updateBeesPositions();
    //reset all states for each tick
    void cleanSlateForTick();
    //assign new targets to bees according to flower and bee status
    void assignNewTargets();
};


#endif //UNTITLED_GARDEN_H
