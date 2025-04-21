CXX = g++
CXXFLAGS = -std=c++17 -pthread -O2 -Wno-switch-bool
TARGET = main
SRC = maze_new.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	@clear && ./$(TARGET)

clean:
	rm -f $(TARGET)