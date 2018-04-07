#Created by Eliaquim dos Santos
PROG = main
CC = g++
CPPFLAGS = -Wall -std=c++11 -pedantic -I./include
OBJS = main.o data.o funcionario.o empresa.o cadastro.o run.o
SRC = ./src/

$(PROG):$(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(PROG) 
	mv *.o ./build
	mv main ./bin
	
main.o:
	$(CC) $(CPPFLAGS) -c  $(SRC)main.cpp
run.o:
	$(CC) $(CPPFLAGS) -c $(SRC)run.cpp
cadastro.o:
	$(CC) $(CPPFLAGS) -c $(SRC)cadastro.cpp
empresa.o:
	$(CC) $(CPPFLAGS) -c $(SRC)empresa.cpp
funcionario.o:
	$(CC) $(CPPFLAGS) -c $(SRC)funcionario.cpp
data.o:
	$(CC) $(CPPFLAGS) -c $(SRC)data.cpp
clean:
	`rm -f core ./build/*.o` 
