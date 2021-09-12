//
// Created by meeve on 11.09.2021.
//

#ifndef SEMESTER3_GAS_H
#define SEMESTER3_GAS_H

#include <random>
#include <cmath>

#include <SFML/System/Vector2.hpp>

class Gas {
public:
    sf::Vector2f pos;
    sf::Vector2f velocity;

    void create();
    void movement();
};

#endif //SEMESTER3_GAS_H
