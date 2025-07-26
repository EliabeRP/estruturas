CXX = g++

CXXFLAGS = -Wall -std=c++17 -Iinclude

all: program test

program: test_sequential.cpp sequential.cpp
	$(CXX) $(CXXFLAGS) test_sequential.cpp sequential.cpp -o program

test: test_sequential.cpp sequential.cpp
	$(CXX) $(CXXFLAGS) test_sequential.cpp sequential.cpp -o test

clean:
	rm -f program test
