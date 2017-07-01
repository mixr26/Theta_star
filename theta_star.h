#ifndef THETA_STAR_H
#define THETA_STAR_H
#include "maze.h"
#include <queue>
#include <set>

struct less_than {
    bool operator()(Cell* const& lhs, Cell* const& rhs) const {
        return lhs->get_g_and_h() < rhs->get_g_and_h();
    }
};

class Theta_star
{
protected:
    Maze m;
    std::priority_queue<Cell*, std::vector<Cell*>, less_than> open;
    std::vector<Cell*> closed;

    float heuristic(Cell* s, Cell* goal);
    void compute_cost(Cell* s, Cell* ss);
    void update_vertex(Cell* s, Cell* neighbour);
    bool line_of_sight(Cell* s, Cell* ss);
    std::vector<Cell*> reconstruct_path(Cell* s);
    bool is_in_closed(Cell* s);
    bool is_in_open(Cell* s);
public:
    Theta_star();
    std::vector<Cell*> do_the_magic(Cell* start, Cell* goal);
};

#endif // THETA_STAR_H
