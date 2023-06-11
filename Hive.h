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
    sf::Color color;
    int beeCount;
    int beeCapacity;
    vector<Bee*> bees;
    sf::CircleShape shape;
    int mapSize;

public:
    // constructor
    Hive(int x, int y, int beeCapacity, int mapSize);
    // destructor
    ~Hive();
    //getBees
    vector<Bee*> getBees();
    // print
    void print();
    // add bee
    bool addBee(Bee *bee);
    // make it full
    void makeFull();
    // draw
    void draw(sf::RenderWindow &window);
    // update
    void update();
};


#endif //UNTITLED_HIVE_H
