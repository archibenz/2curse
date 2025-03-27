# Makefile for compiling the project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Directories
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj

# Target executable
TARGET = mypr3

# Source files
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/functions.cpp

# Object files
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Include directory
INCLUDES = -I$(INCLUDE_DIR)

# Build target
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJ)

# Object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean target: remove object files and executable
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Clean only object files
clean-objects:
	rm -f $(OBJ_DIR)/*.o

