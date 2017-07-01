#include "theta_star.h"

Theta_star::Theta_star() {

}

float Theta_star::heuristic(Cell* s, Cell* goal) {

}

float Theta_star::compute_cost(Cell* s, Cell* ss) {

}

bool Theta_star::line_of_sight(Cell* s, Cell* ss) {

}

void Theta_star::reconstruct_path(Cell* s) {

}

bool Theta_star::is_in_closed(Cell* s) {
    for (int i = 0; i < closed.size(); i++) {
        if (s == closed[i]) {
            return true;
        }
    }

    return false;
}

void Theta_star::update_vertex(Cell* s, Cell* neighbour, Cell *goal) {
    if (line_of_sight(s->get_parent(), neighbour)) {
        if (s->get_parent()->get_g_value() + compute_cost(s->get_parent(), neighbour) < neighbour->get_g_value()) {
            neighbour->set_g_value(s->get_parent()->get_g_value() + compute_cost(s->get_parent(), neighbour));
            neighbour->set_parent(s->get_parent());
            if (open.find(neighbour)) {
                open.remove(neighbour);
            }
            neighbour->set_g_and_h(neighbour->get_g_value() + heuristic(neighbour, goal));
            open.push(neighbour);
        }
    } else {
        if (s->get_g_value() + compute_cost(s, neighbour) < neighbour->get_g_value()) {
            neighbour->set_g_value(s->get_g_value() + compute_cost(s, neighbour));
            neighbour->set_parent(s);
            if (open.find(neighbour)) {
                open.remove(neighbour);
            }
            neighbour->set_g_and_h(neighbour->get_g_value() + heuristic(neighbour, goal));
            open.push(neighbour);
        }
    }
}

std::vector<Cell*> Theta_star::do_the_magic(Cell* start, Cell* goal) {
    //Initialization
    Cell* s;
    std::vector<Cell*>* neighbours;

    start->set_g_value(0);
    start->set_parent(start);
    start->set_g_and_h(start->get_g_value() + heuristic(start, goal));
    open.push(start);

    //Loop
    while (!open.empty()) {
        s = open.top();
        open.pop();

        if (s == goal) {
            reconstruct_path(s);
            return path;
        }

        closed.push_back(s);
        neighbours = s->get_neighbours();
        for (int i = 0; i < s->get_neighbours()->size(); i++) {
            Cell* n = (*neighbours)[i];
            if (!is_in_closed(n)) {
                if (!open.find(n)) {
                    n->set_g_value(INFINITY);
                    n->set_parent(NULL);
                }
                update_vertex(s, n, goal);
            }
        }
    }

    return path;
}
