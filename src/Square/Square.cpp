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
    velocity += acceleration * delay;
    pos += velocity * delay + acceleration * delay * delay / 2.0f;
}

void Square::recover(sf::Vector2f gas_pos) {
    sf::Vector2f dr(std::abs(gas_pos.x - pos.x), std::abs(gas_pos.y - pos.y));
    if (dr.x < r && dr.y < r) health += 10;
}

void Square::Bar_interaction(int check, Barrier v) {
    auto pos1 = velocity * delay + acceleration * delay * delay / 2.0f;

    if (check == 0) {
        if (pos1.y > v.y and pos.x < v.x + v.dx and pos.x > v.x and pos1.y < v.y + v.dy) {
            velocity.y = 0;
            acceleration.y = 0;
        } else acceleration.y = G_down;
    }

    if (check == 1) {
        if (pos1.x < v.x + v.dx and pos1.y < v.y + v.dy and pos1.y > v.y) {
            velocity.x = 0;
            acceleration.x = 0;
        } else acceleration.x = -G_left;
    }

    if (check == 2) {
        if (pos1.y > v.y and pos.x < v.x + v.dx and pos.x > v.x and pos1.y < v.y + v.dy) {
            velocity.y = 0;
            acceleration.y = 0;
        } else acceleration.y = -G_down;
    }
}

int Square::Key_interaction(Key k, int check) {
    float dx = (k.x - tr_r - pos.x + r);
    float dy = (k.y - tr_r - pos.y + r);
    if ((dx * dx + dy * dy) < 1600) {
        health -= 10;
    }
    if (fabsf(dx) < 5 && fabsf(dy) < 5) // release of the hostage
        {
        velocity.x = 0;
        velocity.y = 0;
        check++;
        }
    return check;
}

void Square::draw(sf::RenderWindow &window) {
    sf::CircleShape circle1(r, 4);
    circle1.setFillColor(sf::Color(230, 0, 230));
    circle1.move(pos.x, pos.y);
    window.draw(circle1);
}