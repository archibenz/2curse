CXX = g++
CXXFLAGS = -std=c++17 -pthread -O2 -Wno-switch-bool
TARGET = main
SRC = maze_new.cpp

# SFML через Homebrew
SFML_PREFIX := $(shell brew --prefix sfml@2)
SFML_CFLAGS  := -I$(SFML_PREFIX)/include
SFML_LDFLAGS := -L$(SFML_PREFIX)/lib -lsfml-graphics -lsfml-window -lsfml-system

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SFML_CFLAGS) -o $(TARGET) $(SRC) $(SFML_LDFLAGS)

run: $(TARGET)
	@clear && ./$(TARGET)

clean:
	rm -f $(TARGET)