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
    for(int i = 0; i < hives.size(); i++) {
        delete hives[i];
    }
};

// print
void Garden::print() {
    std::cout << "Garden: size=" << mapSize << std::endl;
    // print hives
    for (int i = 0; i < hives.size(); i++) {
        hives[i]->print();
    }
}

// add hive
bool Garden::addHive(Hive *hive) {
    if (actualHives < maxHives) {
        hives.push_back(hive);
        flowerCount++;
        return true;
    } else {
        std::cout << "Garden is full" << std::endl;
        return false;
    }
}


// add hives
void Garden::addHives(int hiveCount, int beeCapacity) {
    for (int i = 0; i < hiveCount; i++) {
        addHive(new Hive(rand() % mapSize, rand() % mapSize, beeCapacity));
    }
}

// make hives full
void Garden::makeHivesFull() {
    for (int i = 0; i < hives.size(); i++) {
        hives[i]->makeFull();
    }
}

// draw
void Garden::draw(sf::RenderWindow &window) {
    // draw hives
    for (int i = 0; i < hives.size(); i++) {
        hives[i]->draw(window);
    }
}

// update
void Garden::update() {
    // update hives
    for (int i = 0; i < hives.size(); i++) {
        hives[i]->update();
    }
}