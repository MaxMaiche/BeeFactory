//
// Created by Coralie Desquiens on 11/06/2023.
//
#include <iostream>
#include "Flower.h"

using namespace std;


Flower::Flower(int x, int y, int score) : x(x), y(y), score(score) {
    color = sf::Color::White;
    //std::cout << "Flower created" << std::endl;
}

Flower::~Flower() = default;

void Flower::setScore(int newScore) {
    this->score = newScore;
}

int Flower::getX() const {
    return x;
}

int Flower::getY() const {
    return y;
}

vector<Bee*> & Flower::getBeesThatFollow() {
    return beesThatFollow;
}

void Flower::addBeeThatFollow(Bee *bee) {
    beesThatFollow.push_back(bee);
}

void Flower::removeBeeThatFollow(Bee *bee) {
    for (int i = 0; i < beesThatFollow.size(); i++) {
        if (beesThatFollow[i] == bee) {
            beesThatFollow.erase(beesThatFollow.begin() + i);
            break;
        }
    }
}

vector<Bee*> Flower::clearBeesThatFollow() {
    vector<Bee*> bees = beesThatFollow;
    for(auto & bee : beesThatFollow) {
        bee->makeBeesStopFollowing();
    }
    beesThatFollow.clear();
    return bees;
}

bool Flower::beenManged() {
    score--;
    if (score <= 0) return true;
    return false;
}


bool Flower::isDead() {
    if (score <= 0) return true;
    return false;
}

void Flower::print() const {
    cout << "Flower { x=" << x << ", y=" << y << ", score=" << score << "}" << endl;
}

// draw
void Flower::draw(sf::RenderWindow &window) const {
    sf::CircleShape shape(10.f, 4);
    shape.setFillColor(color);
    shape.setPosition(x, y);
    window.draw(shape);
}