//
// Created by meeve on 11.09.2021.
//

#include <SFML/Graphics.hpp>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <sstream>

#include "Key/Key.h"
#include "Square/Square.h"
#include "Gas/Gas.h"

#include "constants.h"

using namespace sf;
using namespace std;

int main() {
    sf::Font font;//font class
    font.loadFromFile("CyrilicOld.TTF");

    int check = -1; // game mode

    srand(time(nullptr));
    RenderWindow window(VideoMode(H, L), "Movement");

    vector<Key> keys;

    int g = 10;
    Key element{};

    element.x = L - 50;
    element.y = 50;
    keys.push_back(element);

    element.x = 50;
    element.y = H - 50;
    keys.push_back(element);

    element.x = L / 2;
    element.y = H / 2;
    keys.push_back(element);

    Gas *mass = new Gas[N];
    //Barrier* mass_of_bar = new Barrier[4];
    vector<Barrier> v;

    Square object;
    object.r = 10;
    object.health = 1000;
    object.pos = sf::Vector2f(100.0f, 100.0f);
    object.velocity = sf::Vector2f(0.0f, -40.0f);
    object.acceleration = sf::Vector2f(0, G_down);

    for (int i = 0; i < N; i++) {
        mass[i].create();
    }

    // Variables for timer and delay
    float timer = 0; //, delay = 0.1;
    Clock clock;

    while (window.isOpen()) {

        // Main menu before the game
        if (check == -1) {
            window.clear(Color::White);
            int R = 40;
            int Button_x = L / 2 - R;
            int Button_y = H / 2 + R;

            CircleShape circle5(R, 4);
            circle5.setFillColor(Color(230, 0, 230));
            circle5.move(Button_x, Button_y);
            window.draw(circle5);


            Text text1;
            text1.setFont(font);
            text1.setCharacterSize(20);
            text1.setFillColor(sf::Color::Blue);


            text1.setString("Квадрат борится за справедливость! ");
            text1.setPosition(L / 4, H / 4);
            window.draw(text1);


            Event event1;
            while (window.pollEvent(event1)) {
                if (event1.type == Event::Closed) window.close();
                if (event1.type == sf::Event::MouseButtonPressed) {
                    if (event1.mouseButton.button == sf::Mouse::Left) {
                        int Mouse_x = event1.mouseButton.x;
                        int Mouse_y = event1.mouseButton.y;
                        if (Mouse_x < Button_x + 2 * R and Mouse_x > Button_x and Mouse_y > Button_y and
                            Mouse_y < Button_y + R * 2) {
                            check++;
                        }
                    }
                }
            }
        }

        // The game itself
        if (check >= 0 and check < 3) {
            std::cout << object.acceleration.x << " " << object.acceleration.y << std::endl;
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;

            Event event;
            if (object.health > 0) {
                while (window.pollEvent(event)) {
                    if (event.type == Event::Closed) window.close();

                    if (event.key.code == Keyboard::Up) {
                        if (check == 0) {// pull down
                            object.velocity.y = -80;
                            object.acceleration.y = G_down;
                        }
                        if (check == 1 or check == 2) { // pull left and up
                            object.pos.y -= 2;
                        }
                    }

                    if (event.key.code == Keyboard::Down) {
                        if (check == 0 or check == 1) object.pos.y += 2; // pull down and left
                        if (check == 2) { // pull up
                            object.velocity.y = 80;
                            object.acceleration.y = -G_down;
                        }
                    }

                    if (event.key.code == Keyboard::Left) object.pos.x -= 2;
                    if (event.key.code == Keyboard::Right) {
                        if (check == 0) object.pos.x += 2; // pull down and up
                        if (check == 2) object.pos.x += 2;
                        if (check == 1) {
                            object.velocity.x = -80;
                            object.acceleration.x = -G_left;
                        }
                    }

                    if (event.key.code == Keyboard::W) {
                        Barrier bar_up{object.pos.x + r - 25, 0, 50,
                                       object.pos.y}; // x, y, dx, dy  object.x - верхний левый угол
                        v.push_back(bar_up);
                    }

                    if (event.key.code == Keyboard::D) {
                        Barrier bar_up{object.pos.x + 2 * object.r, object.pos.y + object.r - 25, 4, 50}; // x, y, dx, dy
                        v.push_back(bar_up);
                    }

                    if (event.key.code == Keyboard::S) {
                        Barrier bar_up{object.pos.x + r - 25, object.pos.y + 2 * object.r, 50,
                                       H - object.pos.y}; // x, y, dx, dy  object.x - верхний левый угол
                        v.push_back(bar_up);
                    }

                    if (event.key.code == Keyboard::A) {
                        Barrier bar_up{0, object.pos.y + r - 25, object.pos.x - 2 * object.r, 50}; // x, y, dx, dy
                        v.push_back(bar_up);
                    }

                }

                if (timer > delay) {
                    // движение шаров
                    for (int i = 0; i < N; i++) {
                        mass[i].movement();
                        object.recover(mass[i].pos); // пополнение здоровья
                    }

                    // движение объекта
                    object.movement();

                    //  взаимодействие объекта с барьером
                    for (int i = 0; i < v.size(); i++) {
                        object.Bar_interaction(check, v[i]);
                    }

                    // ключ и объект
                    for (int i = 0; i < keys.size(); i++) {
                        int check1 = check;
                        check = object.Key_interaction(keys[i], check);
                        if (check1 < check) {
                            keys.erase(keys.begin() + i);
                            v.clear();
                        }
                    }

//                     проверка на выход за границы
                    if (object.pos.x < 0 or object.pos.x > L or object.pos.y < 0 or object.pos.y > H) object.health = 0;
                    timer = 0;
                }
            }

            window.clear(Color::White);
            if (check == 1) {
                object.acceleration = sf::Vector2f(0, -G_left);
            }

            if (check == 2) {
                object.acceleration = sf::Vector2f(-G_down, 0);
            }

            for (int i = 0; i < v.size(); i++) { // барьеры
                v[i].draw(window);
            }

            for (int i = 0; i < keys.size(); i++) { // ключи
                keys[i].draw(window);
            }

            for (int i = 0; i < N; i++) { // рисую круги
                mass[i].draw(window);
            }

            // рисую объект
            object.draw(window);

            // вывод на экран здоровье персонажа
            Text text;
            text.setFont(font);
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::Blue);

            stringstream objectHealth;
            objectHealth << object.health;
            text.setString(" Здоровье:" + objectHealth.str());
            text.setPosition(L / 2, 0);
            window.draw(text);
        }

        if (object.health <= 0) {
            Event event1;
            while (window.pollEvent(event1)) {
                // Пользователь нажал на «крестик» и хочет закрыть окно?
                if (event1.type == Event::Closed) {
                    // тогда закрываем его
                    window.close();
                }
            }

            Text text2;
            text2.setFont(font);
            text2.setCharacterSize(35);
            text2.setFillColor(sf::Color::Blue);

            text2.setString("Ты проиграл ! ");
            text2.setPosition(L / 4, H / 4);
            window.draw(text2);
        }

        if (check == 3) {
            window.clear(Color::White);
            Text text1;
            text1.setFont(font);
            text1.setCharacterSize(20);
            text1.setFillColor(sf::Color::Blue);

            text1.setString("Ты победил ! ");
            text1.setPosition(L / 4, H / 4);
            window.draw(text1);
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) window.close();
                //if (object.health < 0) window.close();
            }
        }
        window.display();
    }

    delete[] mass;
    return 0;
}
