#include "../include/my_queue.h"

bool My_queue::find(Cell* s) {
    for (auto it = this->c.begin(); it != this->c.end(); ++it) {
        if (*it == s) {
            return true;
        }
    }

    return false;
}

void My_queue::remove(Cell* s) {
    for (auto it = this->c.begin(); it != this->c.end(); ++it) {
        if (*it == s) {
            this->c.erase(it);
        }
    }
}

