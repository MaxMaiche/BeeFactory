//
// Created by Max on 10/06/2023.
//

#ifndef UNTITLED_HIVE_H
#define UNTITLED_HIVE_H

#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class Bee;
class Flower;

class Hive {
private:

    int x;
    int y;
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
    // getX
    int getX() const;
    // getY
    int getY() const;
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
    // update
    void update();
    // make bees follow mouse
    void makeHivesFollow(int x, int y);
    // make bees stop following mouse
    void makeHivesStopFollowing();
};


#endif //UNTITLED_HIVE_H
