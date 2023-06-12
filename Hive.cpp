//
// Created by Max on 10/06/2023.
//
#include <iostream>
#include <vector>
#include "Hive.h"
#include "Bee.h"

// constructor
Hive::Hive(int x, int y, int beeCapacity, int mapSize) {
    this->x = x;
    this->y = y;
    this->beeCapacity = beeCapacity;
    this->beeCount = 0;
    this->mapSize = mapSize;

    // random color
    this->color = sf::Color(rand() % 255, rand() % 255, rand() % 255);


    //std::cout << "Hive created" << std::endl;
}

// destructor
Hive::~Hive() {
    for (int i = 0; i < beeCount; i++) {
        delete bees[i];
    }
}

// getX
int Hive::getX() const{
    return x;
}

// getY
int Hive::getY() const{
    return y;
}

// getScore
int Hive::getScore() const{
    return score;
}

// getBees
std::vector<Bee*> & Hive::getBees() {
    return bees;
}

// print
void Hive::print() {
    std::cout << "Hive: x=" << x << ", y=" << y << ", beeCapacity=" << beeCapacity << std::endl;
    // print bees
    for (int i = 0; i < beeCount; i++) {
        bees[i]->print();
    }
}

// add bee
bool Hive::addBee(Bee* bee) {
    if (beeCount < beeCapacity) {
        bees.push_back(bee);
        beeCount++;
        return true;
    } else {
        //std::cout << "Hive is full" << std::endl;
        return false;
    }
}

// make it full
void Hive::makeFull() {
    while (addBee(new Bee(1, x, y, color, mapSize)));
}

// add score
void Hive::addScore(int score) {
    this->score += score;
}

// draw
void Hive::draw(sf::RenderWindow &window) {
    // draw hive
    sf::CircleShape shape(10);
    shape.setFillColor(color);
    shape.setPosition(x, y);
    window.draw(shape);

    // draw bees
    for (int i = 0; i < beeCount; i++) {
        bees[i]->draw(window);
    }
}


// update
void Hive::update() {
    // update bees
    for (int i = 0; i < beeCount; i++) {
        bees[i]->update();
    }
}

// make bees follow mouse
void Hive::makeHivesFollow(int x, int y) {
    for (int i = 0; i < beeCount; i++) {
        bees[i]->makeBeesFollow(x, y);
    }
}

// make bees stop following mouse
void Hive::makeHivesStopFollowing() {
    for (int i = 0; i < beeCount; i++) {
        bees[i]->makeBeesStopFollowing();
    }
}