#ifndef MY_QUEUE_H
#define MY_QUEUE_H
#include <queue>
#include "cell.h"

struct greater_than {
    bool operator()(Cell* const& lhs, Cell* const& rhs) const {
        return lhs->get_g_and_h() > rhs->get_g_and_h();
    }
};

class My_queue : public std::priority_queue<Cell*, std::vector<Cell*>, greater_than> {
public:
    bool find(Cell* s);
    void remove(Cell* s);
};

#endif // MY_QUEUE_H
