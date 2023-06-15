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
    int Capacity;

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
    int getAge();

    // getNearestFlower
    Flower* getNearestFlower() const;
    // print
    void print();
    // draw
    void draw(sf::RenderWindow &window);
    // updateposition
    void updateposition();
    // isIn
    bool isIn(int tx, int ty, int delta) const;
    // pick up pollen
    void pickUpPollen(Flower* flower);
    // drop pollen
    int dropPollen();
    // test is full
    bool isFull();
    //test if empty
    bool isEmpty();
    //get target
    BeeTarget* getTarget();
    //set target
    void setTarget(BeeTarget*);
    //follow flower
    void follow(Flower* flower);
    //follow Hive
    void follow(Hive* hive);
    //check if bee need to head for hive
    bool needsToHeadToHive();
};

#endif //UNTITLED_BEE_H
