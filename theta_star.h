#ifndef THETA_STAR_H
#define THETA_STAR_H
#include "maze.h"
#include "my_queue.h"
#include <set>

class Theta_star
{
protected:
    Maze m;
    My_queue open;
    std::vector<Cell*> closed;
    std::vector<Cell*> path;

    float heuristic(Cell* s, Cell* goal);
    float compute_cost(Cell* s, Cell* ss);
    void update_vertex(Cell* s, Cell* neighbour, Cell* goal);
    bool line_of_sight(Cell* s, Cell* ss);
    void reconstruct_path(Cell* s);
    bool is_in_closed(Cell* s);
public:
    Theta_star();
    std::vector<Cell*> do_the_magic(Cell* start, Cell* goal);
};

#endif // THETA_STAR_H
