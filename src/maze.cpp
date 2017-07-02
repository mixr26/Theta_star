#include "../include/maze.h"

Maze::Maze() {
    preprocess_maze();

    //obstacle testing
    for (int i = 2; i < MAZE_HEIGHT - 2; i++) {
        maze[i][15].set_blocked(true);
    }

    postprocess_maze();
}

void Maze::preprocess_maze(void) {
    //set the coordinates
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze[i][j].set_x(j);
            maze[i][j].set_y(i);
        }
    }
}

void Maze::postprocess_maze(void) {
    int newx, newy;

    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            std::vector<Cell*>* neigh = maze[y][x].get_neighbours();
            for (int d = 0; d < DIRECTIONS; d++) {
                newy = y + dy[d];
                newx = x + dx[d];
                if (newy >= 0 && newy < MAZE_HEIGHT && newx >= 0 && newx < MAZE_WIDTH) {
                    if (!maze[newy][newx].get_blocked()) {
                        neigh->push_back(&maze[newy][newx]);
                    }
                }
            }
        }
    }
}

void Maze::print_maze(void) {
    for (int i = 0; i < MAZE_WIDTH + 2; i++) {
        std::cout << "X";
    }
    std::cout << std::endl;

    for (int i = 0; i < MAZE_HEIGHT; i++) {
        std::cout << "X";
        for (int j = 0; j < MAZE_WIDTH; j++) {
            if (maze[i][j].get_blocked()) {
                std::cout << "X";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "X";
        std::cout << std::endl;
    }

    for (int i = 0; i < MAZE_WIDTH + 2; i++) {
        std::cout << "X";
    }
    std::cout << std::endl << std::endl << std::endl;
}

void Maze::print_cell_neighbours(int x, int y) {
    std::vector<Cell*>* neigh = maze[y][x].get_neighbours();
    for (int i = 0; i < neigh->size(); i++) {
        std::cout << "x: " << (*neigh)[i]->get_x() << " y: " << (*neigh)[i]->get_y() << std::endl;
    }
}
