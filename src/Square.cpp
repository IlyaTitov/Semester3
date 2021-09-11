//
// Created by meeve on 11.09.2021.
//

#include "Square.h"
#include <cmath>

#include "constants.h"

void Square::movement() {
//    vx += g_left * delay;
//    vy += g_down * delay;
//    y += vy * delay + g_down * delay * delay / 2;
//    x -= vx * delay + g_left * delay * delay / 2;
    velocity = acceleration * delay;
    pos = velocity * delay + acceleration * delay * delay / 2.0f;
}

void Square::recover(sf::Vector2f gas_pos) {
    sf::Vector2f dr(std::abs(gas_pos.x - pos.x), std::abs(gas_pos.y - pos.y));
    if (dr.x < r && dr.y < r) health += 10;
}

void Square::Bar_interaction(int check, Barrier v) {
    int y1 = (y + vy * delay + g_down * delay * delay / 2); // the coordinate of the left corner;
    int x1 = x - vx * delay + g_left * delay * delay / 2;
    if (check == 0) {
        if (y1 > v.y and x < v.x + v.dx and x > v.x and y1 < v.y + v.dy) {
            vy = 0;
            g_down = 0;
        } else g_down = G_down;
    }

    if (check == 1) {
        if (x1 < v.x + v.dx and y1 < v.y + v.dy and y1 > v.y) {
            vx = 0;
            g_left = 0;
        } else g_left = G_left;
    }

    if (check == 2) {
        if (y1 > v.y and x < v.x + v.dx and x > v.x and y1 < v.y + v.dy) {
            vy = 0;
            g_down = 0;
        } else g_down = -G_down;
    }
}

int Square::Key_interaction(Key k, int check) {
    float dx = (k.x - tr_r - x + r);
    float dy = (k.y - tr_r - y + r);
    if ((dx * dx + dy * dy) < 1600) {
        health -= 10;
    }
    if (abs(dx) < 5 && abs(dy) < 5) // release of the hostage
        {
        vx = 0;
        vy = 0;
        check++;
        }
    return check;
}