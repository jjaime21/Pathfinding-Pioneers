# @file Makefile
# @author Noah Melton and Jose Jaime
# @date 2025-02-20
# @brief Makefile for Image Stacker project
# Makefile for compliling the Image Stacker project

# Compiler
CXX = g++

CXXFLAGS = -Wall -Wextra -g

all: program

program: main.o stacker.o
	$(CXX) $(CXXFLAGS) -o program main.o stacker.o
main.o: main.cpp stacker.h
	$(CXX) $(CXXFLAGS) -c main.cpp
stacker.o: stacker.cpp stacker.h
	$(CXX) $(CXXFLAGS) -c stacker.cpp
clean:
	rm -f *.o *~ program
