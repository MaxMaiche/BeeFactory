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
    int actualHives;
    int flowerCount;
    vector<Hive*> hives;
    vector<Flower*> flowers;
    vector<Bee*> beesThatNeedNewFlower;

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
    // Check if a flower score is 0
    void checkFlowerScore();
    // Check Bee on flower or Hive
    void checkBeeOnFlowerOrHive();
    // draw
    void draw(sf::RenderWindow &window) const;
    // update
    void update();
    // make bees follow mouse
    void makeGardenFollow(int x, int y);
    // make bees stop following mouse
    void makeGardenStopFollowing();
    // make bees follow random flower
    void makeGardenFollowRandomFlower();
    // Make one bee follow random flower
    void makeOneBeeFollowRandomFlower(Bee* bee);
    // assign new flower to beethatneednewflower
    void assignNewFlowerToBeeThatNeedNewFlower();
    // check bee full
    void checkBeeFull();
};


#endif //UNTITLED_GARDEN_H
