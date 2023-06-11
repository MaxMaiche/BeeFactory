//
// Created by Max on 11/06/2023.
//

#include "Garden.h"

// constructor
Garden::Garden(int maxHives, int mapSize) {
    this->maxHives = maxHives;
    this->mapSize = mapSize;
    this->flowerCount = 0;
    this->actualHives = 0;
}

// destructor
Garden::~Garden() {
    for(auto & hive : hives) {
        delete hive;
    }
}

// getHives
std::vector<Hive*> Garden::getHives() {
    return hives;
}

// print
void Garden::print() {
    std::cout << "Garden: size=" << mapSize << std::endl;
    // print hives
    for (auto & hive : hives) {
        hive->print();
    }
}

// add hive
bool Garden::addHive(Hive *hive) {
    if (actualHives < maxHives) {
        hives.push_back(hive);
        flowerCount++;
        return true;
    } else {
        //std::cout << "Garden is full" << std::endl;
        return false;
    }
}


// add hives
void Garden::addHives(int hiveCount, int beeCapacity) {
    for (int i = 0; i < hiveCount; i++) {
        addHive(new Hive(rand() % mapSize, rand() % mapSize, beeCapacity, mapSize));
    }
}

// make hives full
void Garden::makeHivesFull() {
    for (auto & hive : hives) {
        hive->makeFull();
    }
}

// draw
void Garden::draw(sf::RenderWindow &window) {
    // draw hives
    for (auto & hive : hives) {
        hive->draw(window);
    }
}

// update
void Garden::update() {
    // update hives
    for (auto & hive : hives) {
        hive->update();
    }
}