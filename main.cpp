#include <iostream>
#include "maze.h"

using namespace std;

int main(void) {
    Maze m;

    m.print_maze();
    m.print_cell_neighbours(15, 15);
}
