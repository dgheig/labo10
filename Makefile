GCC = g++
GXX = $(GCC)

STD = -std=c++11
FLAGS = -Wall
ifdef DEBUG
	FLAGS += -DDEBUG
endif

# SFML = -lsfml-graphics -lsfml-window -lsfml-system

COMPILE = $(GXX) $(STD) $(FLAGS)

SRC = src
OBJ = obj
BUILDS = builds
TESTS = tests

all: labo10 compile_tests clean

main: labo10 clean

compile_tests: # sumLine sumDiag shuffleMatrix vectMinSum

clean: obj_dir
	rm -f $(OBJ)/*

documentation:
	mkdir -p doc && cd doc && mkdir -p doxy && doxygen Doxyfile && make -C doxy/latex && cp doxy/latex/refman.pdf doc.pdf

build_dir:
	mkdir -p $(BUILDS)

obj_dir:
	mkdir -p $(OBJ)

setup: build_dir obj_dir

geometry.o: setup $(SRC)/geometry.h $(SRC)/geometry.cpp
	$(COMPILE) -c $(SRC)/geometry.cpp -o $(OBJ)/geometry.o

labo10.o: setup labo_10_comte_emmanuelle_gallay_david.cpp
	$(COMPILE) -c labo_10_comte_emmanuelle_gallay_david.cpp -o $(OBJ)/labo10.o

labo10: setup geometry.o labo10.o
	$(COMPILE) $(SRC)/geometry.h $(OBJ)/geometry.o $(OBJ)/labo10.o -o $(BUILDS)/labo10

# # TESTS

# sumLine: $(TESTS)/sumLine.cpp matrice.o
# 	$(COMPILE) src/matrice.h $(OBJ)/matrice.o $(TESTS)/sumLine.cpp -o $(BUILDS)/sumLine

# sumDiag: $(TESTS)/sumDiag.cpp matrice.o
# 	$(COMPILE) src/matrice.h $(OBJ)/matrice.o $(TESTS)/sumDiag.cpp -o $(BUILDS)/sumDiag

# shuffleMatrix: $(TESTS)/shuffleMatrix.cpp matrice.o
# 	$(COMPILE) src/matrice.h $(OBJ)/matrice.o $(TESTS)/shuffleMatrix.cpp -o $(BUILDS)/shuffleMatrix

# vectMinSum: $(TESTS)/vectMinSum.cpp matrice.o
# 	$(COMPILE) src/matrice.h $(OBJ)/matrice.o $(TESTS)/vectMinSum.cpp -o $(BUILDS)/vectMinSum