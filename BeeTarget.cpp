//
// Created by Coralie Desquiens on 13/06/2023.
//

#include "BeeTarget.h"

//BeeTarget::BeeTarget() : x(0), y(0) {}
BeeTarget::BeeTarget(int x, int y) : x(x), y(y) {}

BeeTarget::~BeeTarget() = default;

int BeeTarget::getX() const {
    return x;
}

int BeeTarget::getY() const {
    return y;
}

bool BeeTarget::isFlower() const {
    return false;
}

bool BeeTarget::isHive() const {
    return false;
}
