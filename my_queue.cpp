#include "my_queue.h"

bool My_queue::find(Cell* s) {
    for (auto it = this->c.cbegin(); it != this->c.cend(); ++it) {
        if (*it == s) {
            return true;
        }
    }

    return false;
}

void My_queue::remove(Cell* s) {

}

