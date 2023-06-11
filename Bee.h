//
// Created by Max on 10/06/2023.
//
#include <iostream>
#include "Hive.h"
#include <SFML/Graphics.hpp>

#ifndef UNTITLED_BEE_H
#define UNTITLED_BEE_H


// create new Bee class
class Bee {
private:

    int age;
    int x;
    int y;
    sf::Color color;
    sf::CircleShape shape;
    double speed;
    float rotation;
    int mapSize;

public:
    // constructor
    Bee(int age, int x, int y, sf::Color color, int mapSize);

    // destructor
    ~Bee();
    // print
    void print();
    // draw
    void draw(sf::RenderWindow &window);
    // update
    void update();
};

#endif //UNTITLED_BEE_H
