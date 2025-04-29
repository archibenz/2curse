# -------- C++ ---------------------------------------------------------------
CXX          := g++
QT_PREFIX    := $(shell brew --prefix qt@5)          # Homebrew-Qt5
export PKG_CONFIG_PATH := $(QT_PREFIX)/lib/pkgconfig:$(PKG_CONFIG_PATH)

QT_CFLAGS    := $(shell pkg-config --cflags Qt5Widgets)
QT_LIBS      := $(shell pkg-config --libs   Qt5Widgets)

CXXFLAGS     := -std=c++17 -pthread -O2 -Wno-switch-bool $(QT_CFLAGS)

TARGET       := main
SRC          := maze_new.cpp

# SFML (через Homebrew)
SFML_PREFIX  := $(shell brew --prefix sfml@2)
SFML_CFLAGS  := -I$(SFML_PREFIX)/include
SFML_LDFLAGS := -L$(SFML_PREFIX)/lib -lsfml-graphics -lsfml-window -lsfml-system

# -------- Python ------------------------------------------------------------
# папка виртуального окружения
PY_ENV := .venv
PY_BIN  := $(PY_ENV)/bin/python
PIP     := $(PY_ENV)/bin/pip
PY_REQ  := matplotlib               # что ставим в venv

# -------- Цели --------------------------------------------------------------
.PHONY: all run clean venv

all: venv $(TARGET)

# 1. C++-бинарник
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SFML_CFLAGS) -o $@ $^ $(QT_LIBS) $(SFML_LDFLAGS)

# 2. Виртуальное окружение с matplotlib
venv: $(PY_ENV)

$(PY_ENV):
	@echo ">>> Создаём Python-venv и ставим зависимости"
	python3 -m venv $(PY_ENV)
	$(PIP) install --upgrade pip
	$(PIP) install $(PY_REQ)

# запуск
run: all
	@clear && ./$(TARGET)

# полная очистка
clean:
	rm -rf $(TARGET) $(PY_ENV)