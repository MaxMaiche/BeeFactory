//
// Created by Max on 10/06/2023.
//

#ifndef UNTITLED_HIVE_H
#define UNTITLED_HIVE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "BeeTarget.h"

using namespace std;

class Bee;
class Flower;

class Hive : public BeeTarget {
private:
    int score;
    int mapSize;
    int beeCount;
    int beeCapacity;
    sf::Color color;
    vector<Bee*> bees;
    Flower* nearestFlower;
    int actualMinDistance;


public:
    // constructor
    Hive(int x, int y, int beeCapacity, int mapSize);
    // destructor
    ~Hive();
    // getScore
    int getScore() const;
    //getBees
    vector<Bee*> & getBees();
    // getColor
    sf::Color getColor() const;
    // getmapSize
    int getMapSize() const;
    // getNearestFlower
    Flower* getNearestFlower() const;
    // setNearestFlower
    void setNearestFlower(Flower* flower);
    // getActualMinDistance
    int getActualMinDistance() const;
    // setActualMinDistance
    void setActualMinDistance(int distance);
    // print
    void print();
    // add bee
    bool addBee(Bee *bee);
    // make it full
    void makeFull();
    // add score
    void addScore(int score);
    // draw
    void draw(sf::RenderWindow &window);
    // updateposition
    void update();

    bool isHive() const override;

};


#endif //UNTITLED_HIVE_H
