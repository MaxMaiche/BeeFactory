//
// Created by Max on 10/06/2023.
//

#ifndef UNTITLED_HIVE_H
#define UNTITLED_HIVE_H


#include "Bee.h"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class Hive {
private:
    int x;
    int y;
    int score;
    sf::Color color;
    int beeCount;
    int beeCapacity;
    vector<Bee*> bees;
    int mapSize;

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
