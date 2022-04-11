#include <iostream>

#include "theta_star.h"

using namespace std;

int main(void) {
    Theta_star ts;

    auto path = ts.do_the_magic(&(ts.get_maze().get_maze()[0][0]),
                                &(ts.get_maze().get_maze()[19][29]));

    for (auto* cell : path) {
        std::cout << "x: " << cell->get_x() << " y: " << cell->get_y()
                  << std::endl;
    }

    ts.get_maze().print_maze();
}
