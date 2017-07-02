all:
	g++ -o theta_star src/*.cpp include/*.h -std=c++11
clean:
	rm -f theta_star
