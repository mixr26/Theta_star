#include "../include/theta_star.h"

Theta_star::Theta_star() {

}

Maze* Theta_star::get_maze(void) {
    return &m;
}

float Theta_star::heuristic(Cell* s, Cell* goal) {
    float dx = abs(s->get_x() - goal->get_x());
    float dy = abs(s->get_y() - goal->get_y());

    return sqrt(dx * dx + dy * dy);
}

float Theta_star::compute_cost(Cell* s, Cell* ss) {
    float dx = abs(s->get_x() - ss->get_x());
    float dy = abs(s->get_y() - ss->get_y());

    return sqrt(dx * dx + dy * dy);
}

bool Theta_star::line_of_sight(Cell* s, Cell* ss) {
    int x0 = s->get_x();
    int y0 = s->get_y();
    int x1 = ss->get_x();
    int y1 = ss->get_y();
    int dy = y1 - y0;
    int dx = x1 - x0;
    int f = 0;
    int sy = 1;
    int sx = 1;

    if (dy < 0) {
        dy = -dy;
        sy = -1;
    }

    if (dx < 0) {
        dx = -dx;
        sx = -1;
    }

    if (dx >= dy) {
        while (x0 != x1) {
            f += dy;
            if (f >= dx) {
                if (m.maze[y0 + (sy - 1) / 2][x0 + (sx - 1) / 2].get_blocked()) {
                    return false;
                }
                y0 += sy;
                f -= dx;
            }
            if (f != 0 && m.maze[y0 + (sy - 1) / 2][x0 + (sx - 1) / 2].get_blocked()) {
                return false;
            }
            if (dy == 0 && m.maze[y0][x0 + (sx - 1) / 2].get_blocked() && m.maze[y0 - 1][x0 + (sx - 1) / 2].get_blocked()) {
                return false;
            }
            x0 += sx;
        }
    } else {
        while (y0 != y1) {
            f += dx;
            if (f >= dy) {
                if (m.maze[y0 + (sy - 1) / 2][x0 + (sx - 1) / 2].get_blocked()) {
                    return false;
                }
                x0 += sx;
                f -= dy;
            }
            if (f != 0 && m.maze[y0 + (sy - 1) / 2][x0 + (sx - 1) / 2].get_blocked()) {
                return false;
            }
            if (dx == 0 && m.maze[y0 + (sy - 1) / 2][x0].get_blocked() && m.maze[y0 + (sy - 1) / 2][x0 - 1].get_blocked()) {
                return false;
            }
            y0 += sy;
        }
    }

    return true;
}

void Theta_star::reconstruct_path(Cell* s) {
    Cell* prev;
    Cell* next;

    prev = s;
    next = s->get_parent();
    path.push_back(s);
    while (prev != next) {
        path.push_back(next);
        prev = next;
        next = next->get_parent();
    }
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
