//
// Created by meeve on 11.09.2021.
//

#include "Gas.h"
#include <random>

#include "constants.h"

void Gas::create() {
    x = rand() % L + 50;
    y = rand() % H + 50;
    vx = rand() % 200;
    vy = rand() % 200;
}