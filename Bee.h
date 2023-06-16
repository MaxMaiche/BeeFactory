//
// Created by Max on 10/06/2023.
//
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef UNTITLED_BEE_H
#define UNTITLED_BEE_H

class Hive;
class Flower;
class BeeTarget;

// create new Bee class
class Bee {
private:
    int x;
    int y;
    int age;
    int capacity;
    int maxCapacity;

    Hive* hive;
    sf::CircleShape shape;

    double speed;
    float rotation;
    bool isFollowing;
    int followX;
    int followY;

    BeeTarget* target;


public:
    // constructor
    explicit Bee(Hive* hive);

    // destructor
    ~Bee();
    // getX
    int getX() const;
    // getY
    int getY() const;
    // getAge
    int getAge() const;
    // getCapacity
    int getCapacity() const;
    // get maxCapacity
    int getActualCapacity() const;
    // getNearestFlower
    Flower* getNearestFlower() const;
    // print
    void print() const;
    // draw
    void draw(sf::RenderWindow &window);
    // update
    void update();
    // make bees follow mouse
    void makeBeesFollow(int x, int y);
    // make bee follow hive
    void makeBeesFollowHive();
    // make bees stop following mouse
    void makeBeesStopFollowing();
    // isIn
    bool isIn(int tx, int ty, int delta) const;

    // pick up pollen
    void pickUpPollen(int pollen);
    // drop pollen
    int dropPollen();

    // Bee is full
    bool isFull();

    BeeTarget* getTarget();
    void setTarget(BeeTarget*);

};

#endif //UNTITLED_BEE_H
