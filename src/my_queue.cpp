#include <algorithm>

#include "my_queue.h"

// Whether a cell exists in the priority queue.
bool My_queue::find(Cell* s) {
    return std::find(this->c.begin(), this->c.end(), s) != this->c.end();
}

// Remove a cell from the priority queue.
void My_queue::remove(Cell* s) {
    std::remove_if(this->c.begin(), this->c.end(), [=](Cell* cell) {
        return cell == s;
    });
}

