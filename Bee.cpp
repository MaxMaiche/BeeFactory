//
// Created by Max on 10/06/2023.
//
#include <cmath>
#include "Hive.h"
#include "Bee.h"

// constructor
Bee::Bee(int age, int x, int y, sf::Color color) {
    this->age = age;
    this->x = x;
    this->y = y;
    this->color = color;
    this->shape = sf::CircleShape(5, 3);
    shape.setFillColor(color);
    this->speed = 0.1;
    this->rotation = 0;
}

// destructor
Bee::~Bee() = default;

// print
void Bee::print() {
    std::cout << "Bee: age=" << age << ", x=" << x << ", y=" << y << std::endl;
}

// draw
void Bee::draw(sf::RenderWindow &window) {
    shape.setPosition(x, y);
    shape.setRotation(rotation);
    window.draw(shape);
}

// update
void Bee::update() {
    // Variation aléatoire de la direction
    rotation += (rand() % 11) - 5;
    rotation %= 360;

    // Conversion de la rotation en radians
    float radians = rotation * M_PI / 180;

    // Calcul de la nouvelle position
    x += speed * cos(radians);
    y -= speed * sin(radians);

    age++;
}
