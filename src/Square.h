//
// Created by meeve on 11.09.2021.
//

#ifndef SEMESTER3_SQUARE_H
#define SEMESTER3_SQUARE_H

#include <SFML/System/Vector2.hpp>

#include "Barrier.h"
#include "Key.h"

class Square {
public:
    //int x; // coordinates of the centre of the square
    //int y;
    sf::Vector2f pos;
    float r;// the radius of the circumscribed circle
    //int vx;
    //int vy;
    sf::Vector2f velocity;
    int health;
    //int g_down;
    sf::Vector2f acceleration;

    void movement();

    void recover(sf::Vector2f gas_pos);

    void Bar_interaction(int check, Barrier v);

    int Key_interaction(Key k, int check);
};

#endif //SEMESTER3_SQUARE_H
