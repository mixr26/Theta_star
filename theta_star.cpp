#include "theta_star.h"

Theta_star::Theta_star() {

}

float Theta_star::heuristic(Cell* s, Cell* goal) {

}

void Theta_star::compute_cost(Cell* s, Cell* ss) {

}

bool Theta_star::line_of_sight(Cell* s, Cell* ss) {

}

std::vector<Cell*> Theta_star::reconstruct_path(Cell* s) {

}

bool Theta_star::is_in_closed(Cell* s) {

}

bool Theta_star::is_in_open(Cell* s) {

}

void Theta_star::update_vertex(Cell* s, Cell* neighbour) {

}

std::vector<Cell*> Theta_star::do_the_magic(Cell* start, Cell* goal) {
    //Initialization
    Cell* s;
    std::vector<Cell*>* neighbours;
    std::vector<Cell*> empty_vector;

    start->set_g_value(0);
    start->set_parent(start);
    start->set_g_and_h(start->get_g_value() + heuristic(start, goal));
    open.push(start);

    //Loop
    while (!open.empty()) {
        s = open.top();
        open.pop();

        if (s == goal) {
            return reconstruct_path(s);
        }

        closed.push_back(s);
        neighbours = s->get_neighbours();
        for (int i = 0; i < s->get_neighbours()->size(); i++) {
            Cell* n = (*neighbours)[i];
            if (!is_in_closed(n)) {
                if (!is_in_open(n)) {
                    n->set_g_value(INFINITY);
                    n->set_parent(NULL);
                }
                update_vertex(s, n);
            }
        }
    }

    return empty_vector;
}
