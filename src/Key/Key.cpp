//
// Created by Meevere on 12.09.2021.
//

#include "Key.h"
#include "constants.h"

#include <cmath>

Key::Key(int x, int y)
: x(x), y(y) {}

void Key::draw(sf::RenderWindow& window) {
    sf::CircleShape circle5(40);
    circle5.setFillColor(sf::Color(0, 0, 230));
    circle5.move(x + (tr_r - 40) / sqrt(2), y + (tr_r - 40) / sqrt(2));
    window.draw(circle5);

    sf::CircleShape triangle(tr_r, 3);
    triangle.setFillColor(sf::Color(230, 230, 0));
    triangle.move(x, y);
    window.draw(triangle);
}
