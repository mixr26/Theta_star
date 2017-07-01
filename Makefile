all:
	g++ -o theta_star main.cpp cell.h cell.cpp maze.h maze.cpp theta_star.h theta_star.cpp my_queue.h my_queue.cpp -std=c++11

clean:
	rm -f theta_star
