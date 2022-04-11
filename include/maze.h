#ifndef MAZE_H
#define MAZE_H

#include <array>

#include "cell.h"

#define MAZE_WIDTH 30
#define MAZE_HEIGHT 20
#define DIRECTIONS 8

// This class models a rectangular map (playing field) through which we are
// trying to navigate.
class Maze {
public:
    using Maze_type = std::array<std::array<Cell, MAZE_WIDTH>, MAZE_HEIGHT>;

private:
    // Helper arrays for accesing the neighbours of a cell.
    std::array<int, DIRECTIONS> dx = {1, 0, -1, 0, 1, -1, 1, -1};
    std::array<int, DIRECTIONS> dy = {0, 1, 0, -1, 1, -1, -1, 1};
    // Actual 2D array of cells.
    Maze_type maze;

    // Assign the coordinates to the cells.
    void preprocess_maze();
    // Update the neighbour lists of the cells.
    // If the cell's neighbour is an obstacle (blocked), it mustn't be present
    // in the cell's neighbour list.
    void postprocess_maze();

    void populate_neighbours(int x, int y, std::vector<Cell*>& neighbours);

public:
    Maze();

    void print_maze();
    void print_cell_neighbours(int x, int y);

    Maze_type& get_maze() { return maze; }
};

#endif // MAZE_H
