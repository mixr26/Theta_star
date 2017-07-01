#include <iostream>
#include "theta_star.h"

using namespace std;

int main(void) {
    std::set<Cell*, less_than> s;
    Cell c(10, 20, false);
    c.set_g_value(10);
    Cell c2(12, 10, false);
    c2.set_g_value(20);
    s.insert(&c);
    s.insert(&c2);

    Cell* pt1 = &c;
    Cell* pt2 = &c;

    if (pt1 != pt2) {
        std::cout << "aaaaaa" << std::endl;
    }
}
