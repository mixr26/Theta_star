#ifndef CELL_H
#define CELL_H

#define DIRECTIONS 4

#include <iostream>
#include <math.h>
#include <vector>

class Cell {
public:
    Cell(int x, int y, bool blocked);
    Cell(void);

    //setters
    void set_x(int x);
    void set_y(int y);
    void set_g_value(float g_value);
    void set_parent(Cell* parent);
    void set_blocked(bool blocked);
    void set_g_and_h(float g_and_h);

    //getters
    int get_x(void);
    int get_y(void);
    float get_g_value(void);
    float get_g_and_h(void);
    Cell* get_parent(void);
    std::vector<Cell*>* get_neighbours(void);
    bool get_blocked(void);
protected:
    int x;
    int y;
    float g_value;
    float g_and_h;
    Cell* parent;
    std::vector<Cell*> neighbours;
    bool blocked;
};

#endif // CELL_H
