# Nombre del ejecutable
TARGET = bio

# Carpetas
SRC_DIR = src
INC_DIR = include

# Archivos fuente y objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJS = $(SRCS:.cpp=.o)

# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I$(INC_DIR)

# Regla principal
all: $(TARGET)

# Cómo compilar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para archivos .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(TARGET) $(SRC_DIR)/*.o *.o

# Ejecutar el programa
run: $(TARGET)
	./$(TARGET)

