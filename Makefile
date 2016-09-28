FLAGS=-Wextra -Wall -Werror -pedantic -std=c99 -lm
COMPILLER=gcc

all: start

start: database.o expression.o parser.o queue.o string.o main.o
	$(COMPILLER) $(FLAGS) -o kp6 database.o parser.o queue.o string.o main.o

main.o: main.c
	$(COMPILLER) -c $(FLAGS) main.c

database.o: database.c
	$(COMPILLER) -c $(FLAGS) database.c

expression.o: expression.c
	$(COMPILLER) -c $(FLAGS) expression.c

note.o: note.c
	$(COMPILLER) -c $(FLAGS) note.c

parser.o: parser.c
	$(COMPILLER) -c $(FLAGS) parser.c

queue.o: queue.c
	$(COMPILLER) -c $(FLAGS) queue.c

string.o: string.c
	$(COMPILLER) -c $(FLAGS) string.c

clear:
	-rm -f *.o *.gch kp8