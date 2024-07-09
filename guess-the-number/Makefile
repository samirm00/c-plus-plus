# Define compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I src

# Define source files and object files
SRCS = main.cpp src/GuessGame.cpp
OBJS = $(SRCS:.cpp=.o)

# Define the executable name
EXEC = GuessGame

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove object files and executable
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean

