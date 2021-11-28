CC=/usr/bin/g++
INCLUDE=include/
SRC=src/
BIN=bin/
CFLAGS=-lsfml-window -lsfml-audio -lsfml-graphics -lsfml-system -I $(INCLUDE) -std=c++11

build:
	@mkdir -p $(BIN)
	@$(CC) $(SRC)/misery.cpp $(SRC)/minion.cpp $(SRC)/game.cpp $(CFLAGS) -o $(BIN)/misery
	@echo compiled successfully

run:
	@./bin/misery