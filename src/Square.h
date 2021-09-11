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
    int x; // coordinates of the centre of the square
    int y;
    int r;// the radius of the circumscribed circle
    int vx;
    int vy;
    int health;
    int g_down;
    int g_left;
    int g_up;



    void movement();

    void recover(int Gas_x, int Gas_y);

    void Bar_interaction(int check, Barrier v);

    int Key_interaction(Key k, int check);
};

#endif //SEMESTER3_SQUARE_H
