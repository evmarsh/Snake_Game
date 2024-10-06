CC = g++
CFLAGS = -g -Wall

SRC = $(shell find src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
BIN = bin

.PHONY: all clean

all: dirs build

dirs:
	mkdir -p ./$(BIN)

run: build
	./$(BIN)/snake

build: dirs $(OBJ)
	$(CC) -o $(BIN)/snake $(filter %.o,$^) -w -lSDL2 $(CFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(BIN)/snake
	rm -rf $(BIN)

db:
	gdb ./$(BIN)/snake
