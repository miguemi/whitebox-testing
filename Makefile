# Definir el compilador
CC = g++

# Opciones de compilación
CFLAGS = -Wall -Wextra -std=c++11

# Directorios de origen y destino
SRCDIR = src
BINDIR = bin

# Lista de archivos fuente
SOURCES := $(wildcard $(SRCDIR)/*.c)

# Generar nombres de archivos objeto
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(BINDIR)/%.o)

# Nombre del ejecutable final
TARGET = whitebox.out

# Regla para construir el ejecutable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Regla para construir los archivos objeto
$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(BINDIR)/*.o $(TARGET)

# Marcar las reglas que no son archivos
.PHONY: clean
