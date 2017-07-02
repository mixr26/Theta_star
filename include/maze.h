#ifndef MAZE_H
#define MAZE_H
#include "cell.h"

#define MAZE_WIDTH 30
#define MAZE_HEIGHT 20
#define DIRECTIONS 8

class Maze {
protected:
    int dx[DIRECTIONS] = {1, 0, -1, 0, 1, -1, 1, -1};
    int dy[DIRECTIONS] = {0, 1, 0, -1, 1, -1, -1, 1};
public:
    Cell maze[MAZE_HEIGHT][MAZE_WIDTH];
    Maze();
    void print_maze(void);
    void print_cell_neighbours(int x, int y);
    void preprocess_maze(void);
    void postprocess_maze(void);
};

#endif // MAZE_H
