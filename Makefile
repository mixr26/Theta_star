all:
	g++ -o theta_star src/main.cpp include/cell.h src/cell.cpp include/maze.h src/maze.cpp include/theta_star.h src/theta_star.cpp include/my_queue.h src/my_queue.cpp -std=c++11

clean:
	rm -f theta_star
