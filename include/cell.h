#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <math.h>
#include <vector>

// This class models a single cell in a maze through which we are navigating.
class Cell {
private:
    // Cell coordinates.
    int x;
    int y;

    // Distance from the start cell to this cell.
    float g_value;
    // Sum of distances from the starting cell this cell, and from this cell
    // to the end cell.
    float g_and_h;

    // If this cell is part of the shortest path, the previous cell in the path
    // will be its parent.
    Cell* parent;

    // List of this cell's neighbours. A neighbour is any cell that is
    // in contact with this cell, and is not blocked.
    std::vector<Cell*> neighbours;
    // If the obstacle exists on the cell's coordinate, consider it blocked.
    bool blocked;

public:
    Cell(int x, int y, bool blocked)
        : x(x), y(y), g_value(INFINITY), parent(nullptr), blocked(blocked) {}
    Cell()
        : x(0), y(0), g_value(INFINITY), parent(nullptr), blocked(false) {}

    // Setters
    void set_x(int x) { this->x = x; }
    void set_y(int y) { this->y = y; }
    void set_g_value(float g_value) { this->g_value = g_value; }
    void set_parent(Cell* parent) { this->parent = parent; }
    void set_blocked(bool blocked) { this->blocked = blocked; }
    void set_g_and_h(float g_and_h) { this->g_and_h = g_and_h; }

    // Getters
    int get_x() { return x; }
    int get_y() { return y; }
    float get_g_value() { return g_value; }
    float get_g_and_h() { return g_and_h; }
    Cell* get_parent() { return parent; }
    std::vector<Cell*>& get_neighbours() { return neighbours; }
    bool is_blocked() { return blocked; }
};

#endif // CELL_H
