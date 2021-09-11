//
// Created by meeve on 11.09.2021.
//

#ifndef SEMESTER3_BARRIER_H
#define SEMESTER3_BARRIER_H

class Barrier {
public:
    int x;//coordinates of the left corner
    int y;
    int *arr;
    int dx; // rectangle length
    int dy; // rectangle width
    Barrier(int inx, int iny, int indx, int indy); // constructor
};

#endif //SEMESTER3_BARRIER_H
