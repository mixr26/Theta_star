#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <queue>

#include "cell.h"

struct greater_than {
    bool operator()(Cell* const& lhs, Cell* const& rhs) const {
        return lhs->get_g_and_h() > rhs->get_g_and_h();
    }
};

// Custom priority queue which allows random access, in addition to standard
// extracting methods.
class My_queue : public std::priority_queue<Cell*,
                                            std::vector<Cell*>,
                                            greater_than> {
public:
    // Whether a cell exists in the priority queue.
    bool find(Cell* s);
    // Remove a cell from the priority queue.
    void remove(Cell* s);
};

#endif // MY_QUEUE_H
