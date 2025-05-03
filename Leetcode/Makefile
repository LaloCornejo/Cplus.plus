CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic -O3 -g

all: logs example

example:
	$(CXX) $(CXXFLAGS) a.cpp -o current
	./current


clean:
	rm -f current
	
logs:
	rm -f output.txt error.txt

.PHONY: all clean logs

