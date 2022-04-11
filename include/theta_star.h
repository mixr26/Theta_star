#ifndef THETA_STAR_H
#define THETA_STAR_H

#include "maze.h"
#include "my_queue.h"

class Theta_star
{
private:
    My_queue open;
    std::vector<Cell*> closed;
    std::vector<Cell*> path;
    Maze maze;

    // Calculates the Euclidean distance between two cells.
    float heuristic(Cell* s, Cell* goal);
    // Update the g and h values of cell's neighbours.
    void update_vertex(Cell* s, Cell* neighbour, Cell* goal);
    // Whether the two cells have LoS.
    bool line_of_sight(Cell* s, Cell* ss);
    // Reconstruct the shortest path, following the parents from goal to start cell.
    void reconstruct_path(Cell* s);
    // Whether this cell is in the "closed" array.
    bool is_in_closed(Cell* s);
public:
    // Find the shortest path.
    std::vector<Cell*> do_the_magic(Cell* start, Cell* goal);

    Maze& get_maze() { return maze; }
};

#endif // THETA_STAR_H
