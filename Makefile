INC=./include
SRC=./src
BIN=./bin
OBJ=./obj

OPT=-Wall -g -std=c++11

all: build

build: $(BIN)/main_exe

$(BIN)/main_exe: $(OBJ)/main.o  $(OBJ)/cromosoma.o $(OBJ)/poblacion.o $(OBJ)/geneticos.o $(OBJ)/utilidades.o $(OBJ)/random.o
	g++ -std=c++11 -I$(INC) $^ -o $@

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/random.h $(INC)/utilidades.h $(INC)/geneticos.h
	g++ -std=c++11 -I$(INC) -c $< -o $@

$(OBJ)/poblacion.o: $(SRC)/poblacion.cpp $(INC)/poblacion.h $(INC)/random.h
	g++ -std=c++11 -I$(INC) -c $< -o $@

$(OBJ)/geneticos.o: $(SRC)/geneticos.cpp $(INC)/geneticos.h $(INC)/poblacion.h
	g++ -std=c++11 -I$(INC) -c $< -o $@

$(OBJ)/cromosoma.o: $(SRC)/cromosoma.cpp $(INC)/cromosoma.h $(INC)/utilidades.h
	g++ -std=c++11 -I$(INC) -c $< -o $@

$(OBJ)/utilidades.o: $(SRC)/utilidades.cpp $(INC)/utilidades.h
	g++ -std=c++11 -I$(INC) -c $< -o $@

$(OBJ)/random.o: $(SRC)/random.cpp $(INC)/random.h
	g++ -std=c++11 -I$(INC) -c $< -o $@

clean:
	rm -rf $(BIN)/* $(OBJ)/*
