#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
//
// Created by Max on 10/06/2023.
//
#include <cmath>
#include <random>
#include "Hive.h"
#include "Bee.h"

// constructor
Bee::Bee(Hive* hive) {
    this->age = 0;
    this->x = hive->getX();
    this->y = hive->getY();
    this->hive = hive;
    this->shape = sf::CircleShape(5, 3);
    shape.setFillColor(hive->getColor());
    this->speed = 1;
    this->rotation = rand() % 360;
    this->isFollowing = false;
    this->followX = 0;
    this->followY = 0;
    this->Capacity = 0;
}

// destructor
Bee::~Bee() = default;

// print
void Bee::print() {
    std::cout << "Bee: age=" << age << ", x=" << x << ", y=" << y << " Rotation="<< rotation <<std::endl;
}

// getAge
int Bee::getAge() {
    return age;
}

// getX
int Bee::getX() const {
    return x;
}

// getY
int Bee::getY() const {
    return y;
}

// getNearestFlower
Flower* Bee::getNearestFlower() const {
    return hive->getNearestFlower();
}

// draw
void Bee::draw(sf::RenderWindow &window) {
    shape.setPosition(x, y);
    shape.setRotation((rotation-30));
    window.draw(shape);
}

// update
void Bee::update() {
    if (!isFollowing) {

        // Variation aléatoire de la direction
        rotation += rand() % 21 - 10;
    } else {
        // Calcul de la rotation pour suivre la cible
        int target_rotation = atan2(followY - y, followX - x) * 180 / M_PI;
        // Calcul de la différence entre la rotation actuelle et la rotation cible
        int delta_rotation = target_rotation - rotation;
        // Si la différence est supérieure à 180°, on tourne dans l'autre sens
        if (delta_rotation > 180) {
            delta_rotation -= 360;
        } else if (delta_rotation < -180) {
            delta_rotation += 360;
        }
        // On tourne dans la direction qui réduit le plus l'écart entre la rotation actuelle et la rotation cible
        int delta = 5;
        if (delta_rotation > 0) {
            rotation += delta;
        } else if (delta_rotation < 0) {
            rotation -= delta;
        }
    }

    if (rotation < 0) {
        rotation += 360;
    } else if (rotation > 360) {
        rotation -= 360;
    }

    // Conversion de la rotation en radians
    float radians = rotation * M_PI / 180;

    // Calcul de la nouvelle position
    x += round(cos(radians)) * speed;
    y += round(sin(radians)) * speed;

    int mapsizetemp = hive->getMapSize();
    // test de bordure
    if (x < 0) x = mapsizetemp-1;
    else if (x > mapsizetemp) x = 0;

    if (y < 0) y = mapsizetemp-1;
    else if (y > mapsizetemp) y = 0;


    // vieillissement
    age++;

}

// make bees follow mouse
void Bee::makeBeesFollow(int f_x, int f_y) {
    isFollowing = true;
    followX = f_x;
    followY = f_y;
}

// make bee follow hive
void Bee::makeBeesFollowHive() {
    isFollowing = true;
    followX = hive->getX();
    followY = hive->getY();
}

// make bees stop following mouse
void Bee::makeBeesStopFollowing() {
    isFollowing = false;
}

// isIn
bool Bee::isIn(int tx, int ty, int delta) const {
    return (x > tx - delta &&
            x < tx + delta &&
            y > ty - delta &&
            y < ty + delta
    );
}

// pick up pollen
void Bee::pickUpPollen() {
    Capacity++;
}

// drop pollen
int Bee::dropPollen() {
    int temp = Capacity;
    Capacity = 0;
    return temp;
}


// Bee is full
bool Bee::isFull() {
    return Capacity == 3;
}