# Nombre del ejecutable
TARGET = compilador

# Compilador
CC = gcc
CFLAGS = -Wall -g

# Archivos objeto (¡Aquí agregamos compiler.o y vm.o!)
OBJS = parser.tab.o lex.yy.o ast.o semantic.o compiler.o vm.o main.o

# Regla principal
all: $(TARGET)

# Cómo generar el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Reglas para los nuevos archivos
compiler.o: compiler.c compiler.h vm.h ast.h
	$(CC) $(CFLAGS) -c compiler.c

vm.o: vm.c vm.h
	$(CC) $(CFLAGS) -c vm.c

# Reglas existentes (Déjalas o adáptalas si son diferentes)
main.o: main.c ast.h semantic.h compiler.h vm.h
	$(CC) $(CFLAGS) -c main.c

ast.o: ast.c ast.h
	$(CC) $(CFLAGS) -c ast.c

semantic.o: semantic.c semantic.h ast.h
	$(CC) $(CFLAGS) -c semantic.c

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

parser.tab.o: parser.tab.c parser.tab.h ast.h
	$(CC) $(CFLAGS) -c parser.tab.c

lex.yy.o: lex.yy.c parser.tab.h
	$(CC) $(CFLAGS) -c lex.yy.c

# Limpieza
clean:
	rm -f $(OBJS) $(TARGET) lex.yy.c parser.tab.c parser.tab.h

run: $(TARGET)
	./$(TARGET) ejemplo.txt