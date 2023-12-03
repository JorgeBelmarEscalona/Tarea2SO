# Nombre del ejecutable
TARGET = version_api

# Compilador
CC = g++

# Opciones de compilación
CFLAGS = -std=c++11 `pkg-config --cflags opencv4` -fopenmp

# Librerías
LIBS = `pkg-config --libs opencv4`

# Archivos fuente
SRCS = testopenmp.cpp

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regla para compilar los archivos objeto
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(TARGET)

# Regla para limpiar los archivos objeto y el ejecutable
clean:
	rm -f $(OBJS) $(TARGET)