#include "maze.h"

Maze::Maze() {
    //set the coordinates
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze[i][j].set_x(j);
            maze[i][j].set_y(i);
        }
    }

    //set the neighbours for the upper edge
    for (int i = 0; i < MAZE_WIDTH; i++) {
        std::vector<Cell*>* neigh = maze[0][i].get_neighbours();
        if (i == 0) {
            neigh->push_back(&maze[0][1]);
            neigh->push_back(&maze[1][0]);
        } else if (i == MAZE_WIDTH - 1) {
            neigh->push_back(&maze[0][MAZE_WIDTH - 2]);
            neigh->push_back(&maze[1][MAZE_WIDTH - 1]);
        } else {
            neigh->push_back(&maze[0][i - 1]);
            neigh->push_back(&maze[0][i + 1]);
            neigh->push_back(&maze[1][i]);
        }
    }

    //set the neighbours for the lower edge
    for (int i = 0; i < MAZE_WIDTH; i++) {
        int j = MAZE_HEIGHT - 1;
        std::vector<Cell*>* neigh = maze[j][i].get_neighbours();
        if (i == 0) {
            neigh->push_back(&maze[j][1]);
            neigh->push_back(&maze[j - 1][0]);
        } else if (i == MAZE_WIDTH - 1) {
            neigh->push_back(&maze[j][MAZE_WIDTH - 2]);
            neigh->push_back(&maze[j - 1][MAZE_WIDTH - 1]);
        } else {
            neigh->push_back(&maze[j][i - 1]);
            neigh->push_back(&maze[j][i + 1]);
            neigh->push_back(&maze[j - 1][i]);
        }
    }

    //set the neighbours for the left and the right edge
    for (int i = 1; i < MAZE_HEIGHT - 1; i++) {
        int j = MAZE_WIDTH - 1;
        std::vector<Cell*>* neigh = maze[i][0].get_neighbours();
        neigh->push_back(&maze[i - 1][0]);
        neigh->push_back(&maze[i + 1][0]);
        neigh->push_back(&maze[i][1]);

        neigh = maze[i][j].get_neighbours();
        neigh->push_back(&maze[i - 1][j]);
        neigh->push_back(&maze[i + 1][j]);
        neigh->push_back(&maze[i][j - 1]);
    }

    //set the neighbours for the remaining cells
    for (int i = 1; i < MAZE_HEIGHT - 1; i++) {
        for (int j = 1; j < MAZE_WIDTH - 1; j++) {
            std::vector<Cell*>* neigh = maze[i][j].get_neighbours();
            neigh->push_back(&maze[i - 1][j]);
            neigh->push_back(&maze[i + 1][j]);
            neigh->push_back(&maze[i][j - 1]);
            neigh->push_back(&maze[i][j + 1]);
        }
    }

    //obstacle testing
    for (int i = 2; i < MAZE_WIDTH - 2; i++) {
        maze[10][i].set_blocked(true);
        maze[11][i].set_blocked(true);
        maze[9][i].set_blocked(true);
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
