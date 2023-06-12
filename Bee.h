//
// Created by Max on 10/06/2023.
//
#include <iostream>
#include <SFML/Graphics.hpp>


#ifndef UNTITLED_BEE_H
#define UNTITLED_BEE_H

// create new Bee class
class Bee {
private:

    int age;
    int x;
    int y;
    int hiveX;
    int hiveY;
    sf::Color color;
    sf::CircleShape shape;
    double speed;
    float rotation;
    int mapSize;
    bool isFollowing;
    int followX;
    int followY;
    int Capacity;

public:
    // constructor
    Bee(int age, int x, int y, sf::Color color, int mapSize);

    // destructor
    ~Bee();
    // getX
    int getX() const;
    // getY
    int getY() const;
    // getAge
    int getAge();
    // print
    void print();
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


    // pick up pollen
    void pickUpPollen();
    // drop pollen
    int dropPollen();

    // Bee is full
    bool isFull();


};

#endif //UNTITLED_BEE_H
