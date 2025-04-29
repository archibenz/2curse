# путь до Qt5 от Homebrew
QT_PREFIX := $(shell brew --prefix qt@5)
export PKG_CONFIG_PATH := $(QT_PREFIX)/lib/pkgconfig:$(PKG_CONFIG_PATH)

CXX        := g++
# подтягиваем cflags и .libs для модуля Qt5Widgets
QT_CFLAGS  := $(shell pkg-config --cflags Qt5Widgets)
QT_LIBS    := $(shell pkg-config --libs   Qt5Widgets)

CXXFLAGS   := -std=c++17 -pthread -O2 $(QT_CFLAGS) -Wno-switch-bool
TARGET     := main
SRC        := maze_new.cpp

# SFML через Homebrew (осталось как у вас)
SFML_PREFIX   := $(shell brew --prefix sfml@2)
SFML_CFLAGS   := -I$(SFML_PREFIX)/include
SFML_LDFLAGS  := -L$(SFML_PREFIX)/lib -lsfml-graphics -lsfml-window -lsfml-system

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SFML_CFLAGS) -o $(TARGET) $(SRC) $(QT_LIBS) $(SFML_LDFLAGS)

run: $(TARGET)
	@clear && ./$(TARGET)

clean:
	rm -f $(TARGET)