//
// Created by meeve on 11.09.2021.
//

#include "Gas.h"
#include <random>

#include "constants.h"

void Gas::create(){
    pos = sf::Vector2f(
            rand() % L + 50,
            rand() % H + 50
            );
    velocity = sf::Vector2f(
            rand() % 200,
            rand() % 200
            );
}

void Gas::movement() {
    if ((pos.x + r) >= L or (pos.x - r) <= 10) {
        velocity.x = -velocity.x;
    }
    if ((pos.y + r) >= H or (pos.y - r) <= 10) {
        velocity.y = -velocity.y;
    }
    pos += velocity * delay;
}

void Gas::draw(sf::RenderWindow& window) {
    sf::CircleShape circle(r);
    circle.setFillColor(sf::Color(0, 230, 230));
    circle.move(pos.x, pos.y);
    window.draw(circle);
}