//
// Created by meeve on 11.09.2021.
//

#ifndef SEMESTER3_KEY_H
#define SEMESTER3_KEY_H

#include <SFML/Graphics.hpp>

// Actually not key but Hostage
class Key {
public:
    int x;
    int y;

    Key() = default;
    Key(int x, int y);

    void draw( sf::RenderWindow& window );
};

#endif //SEMESTER3_KEY_H
