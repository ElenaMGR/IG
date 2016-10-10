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
CFLAGS=    -g -I/usr/include -I$(INC).
CXXFLAGS=  -g -I/usr/include -I$(INC).

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
SOURCES  := $(wildcard $(SRC)*.cc)
INCLUDES := $(wildcard $(INC)*.h)
OBJECTS  := $(SOURCES:$(SRC)%.c=$(OBJ)%.o)

#OBJECTS= $(OBJ)practica1.o $(OBJ)escena.o $(OBJ)ejes.o
# orden que sera ejecutada por defecto
#
default : $(BIN)$(TARGETS)

# regla de ejecucion
#
$(BIN)$(TARGETS) : $(OBJECTS)
	$(CC) -o $@ $(CXXFLAGS) $(OBJECTS) $(LDFLAGS)

#
#

clean:
	rm -f $(OBJ)*.o
	rm -f $(BIN)$(TARGETS)

#
#
redo:
	touch *.cc
	make

#
#
superclean:
	rm -f $(OBJ)*.o
	rm *~
	rm -f $(BIN)$(TARGETS)

#
#
tgz:
	rm -f $(OBJ)*.o
	rm -f $(BIN)$(TARGETS)
	tar -zcvf $(TARGETS).tgz *
