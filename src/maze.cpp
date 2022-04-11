#include "maze.h"

Maze::Maze() {
    preprocess_maze();

    // Obstacle testing.
    for (int i = 1; i < MAZE_HEIGHT; i++) {
        maze[i][15].set_blocked(true);
    }

    postprocess_maze();
}

// Assign the coordinates to the cells.
void Maze::preprocess_maze() {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze[i][j].set_x(j);
            maze[i][j].set_y(i);
        }
    }
}

void Maze::populate_neighbours(int x, int y, std::vector<Cell*>& neighbours) {
    for (int d = 0; d < DIRECTIONS; d++) {
        auto newy = y + dy[d];
        auto newx = x + dx[d];
        if (newy >= 0 && newy < MAZE_HEIGHT && newx >= 0 && newx < MAZE_WIDTH) {
            if (!maze[newy][newx].is_blocked()) {
                neighbours.push_back(&maze[newy][newx]);
            }
        }
    }
}

// Update the neighbour lists of the cells.
// If the cell's neighbour is an obstacle (blocked), it mustn't be present
// in the cell's neighbour list.
void Maze::postprocess_maze() {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            auto& neigh = maze[y][x].get_neighbours();
            populate_neighbours(x, y, neigh);
        }
    }
}

void Maze::print_maze() {
    for (int i = 0; i < MAZE_WIDTH + 2; i++) {
        std::cout << "X";
    }
    std::cout << std::endl;

    for (int i = 0; i < MAZE_HEIGHT; i++) {
        std::cout << "X";
        for (int j = 0; j < MAZE_WIDTH; j++) {
            if (maze[i][j].is_blocked()) {
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
    auto& neighbours = maze[y][x].get_neighbours();
    for (auto* neighbour : neighbours) {
        std::cout << "x: " << neighbour->get_x() << " y: "
                  << neighbour->get_y() << std::endl;
    }
}
