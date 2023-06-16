//
// Created by Coralie Desquiens on 11/06/2023.
//

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bee.h"
#include "BeeTarget.h"

#ifndef LEARNING_FLOWER_H
#define LEARNING_FLOWER_H



using namespace std;

class Flower : public BeeTarget {

private:
    int score;
    sf::Color color;
    vector<Bee*> beesThatFollow;

public:
    Flower(int x, int y, int score);
    ~Flower();

    vector<Bee*> & getBeesThatFollow();
    void addBeeThatFollow(Bee *bee);
    void removeBeeThatFollow(Bee *bee);
    vector<Bee*> clearBeesThatFollow();
    int getScore() const;
    void setScore(int newScore);
    bool beenManged(int nbPollen);
    [[nodiscard]] bool isDead() const;
    [[nodiscard]] int distanceTo(int x, int y) const;
    void print() const;
    void draw(sf::RenderWindow &window) const;

    [[nodiscard]] bool isFlower() const override;

};


#endif //LEARNING_FLOWER_H
