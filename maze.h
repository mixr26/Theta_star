#ifndef MAZE_H
#define MAZE_H
#include "cell.h"

#define MAZE_WIDTH 30
#define MAZE_HEIGHT 20

class Maze {
public:
    Cell maze[MAZE_HEIGHT][MAZE_WIDTH];
    Maze();
    void print_maze(void);
    void print_cell_neighbours(int x, int y);
};

#endif // MAZE_H
