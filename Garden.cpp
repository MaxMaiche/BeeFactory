//
// Created by Max on 11/06/2023.
//

#include "Garden.h"

using namespace std;

// constructor
Garden::Garden(int maxHives, int mapSize) : maxHives(maxHives), mapSize(mapSize){
}

// destructor
Garden::~Garden() {
    for(auto & hive : hives) {
        delete hive;
    }
    for(auto & flower : flowers) {
        delete flower;
    }
}

// getHives
std::vector<Hive*> & Garden::getHives() {
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
    if (hives.size() < maxHives) {
        hives.push_back(hive);
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

// add flower
void Garden::addFlower(Flower *flower) {
    flowers.push_back(flower);
    newFlowers.push_back(flower);
}

// add flowers
void Garden::addFlowers(int nbFlower, int flowerScore) {
    for (int i = 0; i < nbFlower; i++) {
        addFlower(new Flower(rand() % mapSize, rand() % mapSize, flowerScore));
    }
}

// draw
void Garden::draw(sf::RenderWindow &window) const {
    // draw hives and bees
    for (auto & hive : hives) {
        hive->draw(window);
    }
    // draw flowers
    for (auto & flower : flowers) {
        flower->draw(window);
    }
}

// Calculate nearest flower for each hive
void Garden::calculateNearestFlowerForHives() {
    if (flowers.empty()) return;
    if (hives.empty()) return;
    for (auto & hive : hives) {
        hive->setNearestFlower(NULL);
        for (auto & flower : flowers) if (!flower->isDead()){
                if (hive->getNearestFlower() == nullptr ) {
                    hive->setNearestFlower(flower);
                    hive->setActualMinDistance(flower->distanceTo(hive->getX(), hive->getY()));
                } else {
                    if (hive->getActualMinDistance() > flower->distanceTo(hive->getX(), hive->getY())) {
                        hive->setNearestFlower(flower);
                        hive->setActualMinDistance(flower->distanceTo(hive->getX(), hive->getY()));
                    }
                }
            }
    }
}



// move Bees
void Garden::updateBeesPositions() {
    // updateposition hives
    for (auto & hive : hives) {
        hive->update();
    }
}

// pick and/or drop pollen, update bee and hive score
void Garden::checkBeesOnFlowerOrHive() {
    for (auto &hive: hives) {
        for (auto &bee: hive->getBees()) {
            for (auto &flower: flowers) {
                if (bee->isIn(flower->getX(), flower->getY(), 15)
                    && (!flower->isDead() && !bee->isFull())) {
                    // add score to hive
                    bee->pickUpPollen(flower);
                }
            }
            if (bee->isIn(hive->getX(), hive->getY(), 15)) {
                // add score to hive
                hive->addScore(bee->dropPollen());
                //beesThatNeedNewFlower.push_back(bee);
            }
        }
    }
}


Flower* Garden::getRandomFlower() {
    if (flowers.size() > 0) {
        int random = rand() % flowers.size();
        return flowers[random];
    }
    else
        return NULL;
}


// Make one bee follow nearest flower
void Garden::makeOneBeeFollowNearestFlower(Bee *bee) {
    bee->follow(bee->getNearestFlower());
}

// Make bees follow nearest flower
void Garden::makeBeesFollowNearestFlower() {
    for (auto & hive : hives) {
        for (auto & bee : hive->getBees()) {
            makeOneBeeFollowNearestFlower(bee);
        }
    }
}

void Garden::cleanSlateForTick() {
    beesThatNeedNewFlower.clear();
    newFlowers.clear();
    deadFlowers.clear();
}

void Garden::assignNewTargets() {
    //first, check if dead flowers
    for (auto &flower: flowers)
        if (flower->isDead())
            deadFlowers.push_back(flower);

    //then, recompute distances if necessary
    if (newFlowers.size() || deadFlowers.size())
        calculateNearestFlowerForHives();

    //then, adjust targets for bees
    for (auto &hive: hives) {
        for (auto &bee: hive->getBees()) {
            if (bee->needsToHeadToHive() && bee->getTarget() != hive)
                bee->follow(hive);
            else if (bee->getTarget() == NULL ||
                     bee->getTarget()->isFlower() &&
                     (((Flower *) bee->getTarget())->isDead() || bee->getTarget() != bee->getNearestFlower())
                    ) {
                bee->follow(bee->getNearestFlower());
            }
            else if (bee->isEmpty() && bee->getTarget() == hive) {
                cout<<"mpty bee"<<endl;
                bee->follow(bee->getNearestFlower());
            }
        }
    }

    //pluck deadflowers
    std::vector<Flower *> copyFlowers = flowers;
    flowers.clear();
    for (auto &flower: copyFlowers) {
        if (!flower->isDead())
            flowers.push_back(flower);
        else delete flower;
    }

}

/*
void Garden::checkFlowerScore() {
    // make a copy of flowers
    bool oneDead = false;
    vector<Flower*> flowersCopy = flowers;
    vector<Flower*> flowerToDelete = vector<Flower*>();
    for (auto & flower : flowersCopy) {
        if (flower->isDead()) {
            oneDead = true;
            // remove flower from vector
            flowers.erase(std::remove(flowers.begin(), flowers.end(), flower), flowers.end());
            // delete flower
            vector<Bee*> withoutPurposeInLife = flower->clearBeesThatFollow();
            flowerToDelete.push_back(flower);
            flowerCount--;

            // Add bees that need new flower to vector
            for (auto & bee : withoutPurposeInLife) {
                beesThatNeedNewFlower.push_back(bee);
            }
        }
    }

    // to delete flowers
    for (auto & flower : flowerToDelete) {
        for (auto & hive : hives) {
            if(hive->getNearestFlower() == flower) {
                hive->setNearestFlower(nullptr);
            }
        }
        delete flower;
    }

    if (oneDead) {
        calculateNearestFlowerForHives();
    }

}
 */





