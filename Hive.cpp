//
// Created by Max on 10/06/2023.
//
#include <iostream>
#include <vector>
#include "Hive.h"
#include "Bee.h"

// constructor
Hive::Hive(int x, int y, int beeCapacity, int mapSize) : BeeTarget(x, y) {
    this->score = 0;
    this->mapSize = mapSize;
    this->beeCount = 0;
    this->beeCapacity = beeCapacity;
    this->nearestFlower = nullptr;

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

// getScore
int Hive::getScore() const{
    return score;
}

// getBees
std::vector<Bee*> & Hive::getBees() {
    return bees;
}

// getColor
sf::Color Hive::getColor() const{
    return color;
}

// getmapSize
int Hive::getMapSize() const{
    return mapSize;
}

// getNearestFlower
Flower* Hive::getNearestFlower() const{
    return nearestFlower;
}

// setNearestFlower
void Hive::setNearestFlower(Flower* flower) {
    nearestFlower = flower;
}
// getActualMinDistance
int Hive::getActualMinDistance() const{
    return actualMinDistance;
}

// setActualMinDistance
void Hive::setActualMinDistance(int distance) {
    actualMinDistance = distance;
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
    while (addBee(new Bee(this)));
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

bool Hive::isHive() const {
    return true;
}

