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
Bee::Bee(int age, int x, int y, sf::Color color, int mapSize) {
    this->age = age;
    this->x = x;
    this->y = y;
    this->color = color;
    this->shape = sf::CircleShape(5, 3);
    shape.setFillColor(color);
    this->speed = 1;
    this->rotation = rand() % 360;
    this->mapSize = mapSize;
}

// destructor
Bee::~Bee() = default;

// print
void Bee::print() {
    std::cout << "Bee: age=" << age << ", x=" << x << ", y=" << y << " Rotation="<< rotation <<std::endl;
}

// draw
void Bee::draw(sf::RenderWindow &window) {
    shape.setPosition(x, y);
    shape.setRotation((rotation-30));
    window.draw(shape);
}

// update
void Bee::update() {
    // Variation aléatoire de la direction
    rotation += rand() % 21 - 10;

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


    // test de bordure
    if (x < 0) x = mapSize-1;
    else if (x > mapSize) x = 0;

    if (y < 0) y = mapSize-1;
    else if (y > mapSize) y = 0;


    // vieillissement
    age++;


}
