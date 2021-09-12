//
// Created by meeve on 11.09.2021.
//

#include "Barrier.h"

Barrier::Barrier(float inx, float iny, float indx, float indy) // constructor
    : x(inx), y(iny), dx(indx), dy(indy), arr(nullptr) {}

void Barrier::draw(sf::RenderWindow &window) {
    sf::RectangleShape rectangle(sf::Vector2f(dx, dy));
    rectangle.move(x, y);
    rectangle.setFillColor(sf::Color(230, 230, 230));
    window.draw(rectangle);
}