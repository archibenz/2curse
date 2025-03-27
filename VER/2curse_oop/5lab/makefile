# ============ Начало Makefile ============

# Компилятор
CXX = g++

# Флаги компиляции:
CXXFLAGS = -std=c++17 -Wall -Wextra

# Имя выходного файла
TARGET = main

# Правило по умолчанию ("all")
all: $(TARGET)

# Как собрать main (единственный .cpp)
$(TARGET): main.cpp \
           rational.h rational.inl \
           singlylinkedlist.h singlylinkedlist.inl
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

# Уборка
clean:
	rm -f $(TARGET) *.o

# ============ Конец Makefile ============