//
// Created by Coralie Desquiens on 11/06/2023.
//

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bee.h"

#ifndef LEARNING_FLOWER_H
#define LEARNING_FLOWER_H



using namespace std;

class Flower {

private:
    int x;
    int y;
    int score;
    sf::Color color;
    vector<Bee*> beesThatFollow;

public:
    Flower(int x, int y, int score);
    ~Flower();

    int getX() const;
    int getY() const;
    vector<Bee*> & getBeesThatFollow();
    void addBeeThatFollow(Bee *bee);
    void removeBeeThatFollow(Bee *bee);
    vector<Bee*> clearBeesThatFollow();
    void setScore(int newScore);
    bool beenManged();
    bool isDead();
    int distanceTo(int x, int y) const;
    void print() const;
    void draw(sf::RenderWindow &window) const;

};


#endif //LEARNING_FLOWER_H
