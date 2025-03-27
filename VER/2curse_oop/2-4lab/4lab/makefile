CXX = g++
CXXFLAGS = -std=c++17 -Wall
SOURCES = main.cpp cone.cpp ctwo.cpp cthree.cpp cfour.cpp
TARGET = project

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
