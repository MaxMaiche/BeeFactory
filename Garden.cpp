//
// Created by Max on 11/06/2023.
//

#include "Garden.h"

using namespace std;

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
    if (actualHives < maxHives) {
        hives.push_back(hive);
        actualHives++;
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
    flowerCount++;
    flowers.push_back(flower);
    calculateNearestFlowerForHives();
}

// add flowers
void Garden::addFlowers(int nbFlower, int flowerScore) {
    for (int i = 0; i < nbFlower; i++) {
        addFlower(new Flower(rand() % mapSize, rand() % mapSize, flowerScore));
    }
}

// check if a flower score is 0
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

// check bee on flower or hive
void Garden::checkBeeOnFlowerOrHive() {
    for (auto & hive : hives) {
        for (auto & bee : hive->getBees()) {
            for (auto & flower : flowers) {
                if (bee->isIn(flower->getX(), flower->getY(), 15)
                && (!flower->isDead() && !bee->isFull())) {
                    // add score to hive
                    bee->pickUpPollen();
                    flower->beenManged();
                    flower->removeBeeThatFollow(bee);
                    bee->makeBeesFollow(hive->getX(), hive->getY());
                }
            }
            int delta=15;
            if ( bee->isIn(hive->getX(), hive->getY(), delta)) {
                // add score to hive
                hive->addScore(bee->dropPollen());
                beesThatNeedNewFlower.push_back(bee);
            }
        }
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

// update
void Garden::update() {
    // update hives
    for (auto & hive : hives) {
        hive->update();
    }
}

// make bees follow
void Garden::makeGardenFollow(int x, int y)  {
    // make bees follow mouse
    for (auto & hive : hives) {
        hive->makeHivesFollow(x, y);
    }
}

// make bees stop following
void Garden::makeGardenStopFollowing() {
    // make bees stop following mouse
    for (auto & hive : hives) {
        hive->makeHivesStopFollowing();
    }
}

// make one bee follow random flower
void Garden::makeOneBeeFollowRandomFlower(Bee *bee) {

    if (flowers.size() > 0) {
        int random = rand() % flowers.size();
        bee->makeBeesFollow(flowers[random]->getX(), flowers[random]->getY());
        flowers[random]->addBeeThatFollow(bee);
        // delete bee from vector
        beesThatNeedNewFlower.erase(
                std::remove(beesThatNeedNewFlower.begin(), beesThatNeedNewFlower.end(), bee),
                beesThatNeedNewFlower.end());
    }else{
        bee->makeBeesStopFollowing();
    }
}

// make bees follow random flower
void Garden::makeGardenFollow() {
    // make bees stop following mouse
    for (auto & hive : hives) {
        for (auto & bee : hive->getBees()) {
            beesThatNeedNewFlower.push_back(bee);
        }
    }
}

// make bees follow random flower
void Garden::assignNewFlowerToBeeThatNeedNewFlower(){
    // make bees stop following mouse
    for (auto & bee : beesThatNeedNewFlower) {
        if (!bee->isFull()) makeOneBeeFollowNearestFlower(bee); //makeOneBeeFollowRandomFlower(bee);
        else bee->makeBeesFollowHive();
    }
}

// check bee full
void Garden::checkBeeFull() {
    // make bees stop following mouse
    for (auto & hive : hives) {
        for (auto & bee : hive->getBees()) {
            if (bee->isFull()) {
                bee->makeBeesFollowHive();
            }
        }
    }
}

// Calculate nearest flower for each hive
void Garden::calculateNearestFlowerForHives() {
    if (flowers.empty()) return;
    if (hives.empty()) return;
    for (auto & hive : hives) {
        for (auto & flower : flowers) {
            if (hive->getNearestFlower() == nullptr) {
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

// Make one bee follow nearest flower
void Garden::makeOneBeeFollowNearestFlower(Bee *bee) {
    if (bee->getNearestFlower() != nullptr){
        // Maybe bug sur redirection test si abeille deja focus sur fleures
        bee->makeBeesFollow(bee->getNearestFlower()->getX(), bee->getNearestFlower()->getY());
        bee->getNearestFlower()->addBeeThatFollow(bee);
        // delete bee from vector
        beesThatNeedNewFlower.erase(
                std::remove(beesThatNeedNewFlower.begin(), beesThatNeedNewFlower.end(), bee),
                beesThatNeedNewFlower.end());
    } else {
        makeOneBeeFollowRandomFlower(bee);
    }
}

// Make bees follow nearest flower
void Garden::makeBeesFollowNearestFlower() {
    for (auto & hive : hives) {
        for (auto & bee : hive->getBees()) {
            makeOneBeeFollowNearestFlower(bee);
        }
    }
}
