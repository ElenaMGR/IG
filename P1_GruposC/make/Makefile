# fichero Makefile
#
BIN=./bin/
SRC=./src/
INC=./include/
OBJ=./obj/
# nombre del fichero ejecutable
#
TARGETS= practica1

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=    -g -I/usr/include -I.
CXXFLAGS=  -g -I/usr/include -I.

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -lGLU -lGL -lglut

# definicion del compilador
#
CC = g++

# definicion de objetos
#
OBJECTS= $(OBJ)practica1.o $(OBJ)escena.o $(OBJ)ejes.o
SOURCES= $(SRC)practica1.cc $(SRC)escena.cc $(SRC)ejes.cc
# orden que sera ejecutada por defecto
#
default : $(BIN)$(TARGETS)

# regla de ejecucion
#
$(BIN)$(TARGETS) : $(OBJECTS)
	$(CC) -o $@ $(CXXFLAGS) $(OBJECTS) $(LDFLAGS)

# ************ Objetos *************
$(OBJ)practica1.o: $(SRC)practica1.cc
	$(CC) -c $(SRC)practica1.cc -o $(OBJ)practica1.o -I$(INC)
$(OBJ)escena.o: $(SRC)escena.cc
	$(CC) -c $(SRC)escena.cc -o $(OBJ)escena.o -I$(INC)
$(OBJ)ejes.o: $(SRC)ejes.cc
	$(CC) -c $(SRC)ejes.cc -o $(OBJ)ejes.o -I$(INC)


#
#

clean:
	rm -f *.o
	rm -f $(TARGETS)

#
#
redo:
	touch *.cc
	make

#
#
superclean:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)

#
#
tgz:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *
