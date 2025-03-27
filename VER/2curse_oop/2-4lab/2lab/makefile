# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Название выходного файла
TARGET = program

# Файлы исходного кода
SRCS = main.cpp COne.cpp CTwo.cpp

# Файлы объектного кода
OBJS = $(SRCS:.cpp=.o)

# Правило сборки
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Правило компиляции
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJS) $(TARGET)
