# Executable names:
EXE = graph
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o Graph.o Shortest.o BFS.o TourFinder.o 



# Use the cs225 makefile template:
include cs225/make/cs225.mk


