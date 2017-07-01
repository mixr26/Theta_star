all:
	g++ -o theta_star main.cpp cell.h cell.cpp maze.h maze.cpp

clean:
	rm -f theta_star
