//
// Created by meeve on 11.09.2021.
//

#ifndef SEMESTER3_GAS_H
#define SEMESTER3_GAS_H

class Gas {
public:
    int x;
    int y;
    int vx;
    int vy;

    void create() {
        x = rand() % L + 50;
        y = rand() % H + 50;
        vx = rand() % 200;
        vy = rand() % 200;
    }

    //void movement() {}
};

#endif //SEMESTER3_GAS_H
