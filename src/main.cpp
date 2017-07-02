#include <iostream>
#include "../include/theta_star.h"

using namespace std;

int main(void) {
    Theta_star ts;

    std::vector<Cell*> path = ts.do_the_magic(&(ts.m.maze[0][0]), &(ts.m.maze[19][29]));

    for (auto it = path.begin(); it != path.end(); ++it) {
        Cell* help = *it;
        std::cout << "x: " << help->get_x() << " y: " << help->get_y() << std::endl;
    }

    ts.m.print_maze();
}
