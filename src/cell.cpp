#include "../include/cell.h"

Cell::Cell(int x, int y, bool blocked) {
    this->x = x;
    this->y = y;
    this->g_value = INFINITY;
    this->parent = NULL;
    this->blocked = blocked;
}

Cell::Cell(void) {
    this->x = 0;
    this->y = 0;
    this->g_value = INFINITY;
    this->parent = NULL;
    this->blocked = false;
}

void Cell::set_x(int x) {
    this->x = x;
}

void Cell::set_y(int y) {
    this->y = y;
}

void Cell::set_blocked(bool blocked) {
    this->blocked = blocked;
}

void Cell::set_parent(Cell* parent) {
    this->parent = parent;
}

void Cell::set_g_value(float g_value) {
    this->g_value = g_value;
}

void Cell::set_g_and_h(float g_and_h) {
    this->g_and_h = g_and_h;
}

int Cell::get_x(void) {
    return x;
}

int Cell::get_y(void) {
    return y;
}

bool Cell::get_blocked(void) {
    return blocked;
}

Cell* Cell::get_parent(void) {
    return parent;
}

std::vector<Cell*>* Cell::get_neighbours(void) {
    return &neighbours;
}

float Cell::get_g_value(void) {
    return g_value;
}

float Cell::get_g_and_h(void) {
    return g_and_h;
}
