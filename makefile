cc=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB1=my_mat.o
FLAGS= -Wall -g

all: connections
# main
connections: $(OBJECTS_MAIN) my_mat
	$(cc) $(FLAGS) -o connections $(OBJECTS_MAIN) ./my_mat

# lib
my_mat: $(OBJECTS_LIB1)
	$(cc) -shared -o my_mat $(OBJECTS_LIB1)


$(OBJECTS_MAIN): main.c my_mat.h
	$(cc) $(FLAGS) -c main.c
$(OBJECTS_LIB1): my_mat.c my_mat.h
	$(cc) $(FLAGS) -c my_mat.c


.PHONY: clean all
clean:
	rm -f *.o  *.a *.so my_mat connections
