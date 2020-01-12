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
BUILDS = bin
TESTS = tests

all: labo10 compile_tests

cmake: CMakeLists.txt
	mkdir cmake && cd cmake && cmake .. && make


main: labo10

compile_tests: test_point_get test_point_set

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

test_point_get: $(TESTS)/test_point_get.cpp geometry.o
	$(COMPILE) src/geometry.h $(OBJ)/geometry.o $(TESTS)/test_point_get.cpp -o $(BUILDS)/test_point_get

test_point_set: $(TESTS)/test_point_set.cpp geometry.o
	$(COMPILE) src/geometry.h $(OBJ)/geometry.o $(TESTS)/test_point_set.cpp -o $(BUILDS)/test_point_set