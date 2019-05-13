CC := g++ -std=c++11

all: a.out

a.out: main.o CommandHandler.o Comment.o Exceptions.o Film.o GameManager.o Publisher.o User.o
	$(CC) -o a.out main.o CommandHandler.o Comment.o Exceptions.o Film.o GameManager.o Publisher.o User.o

main.o: main.cpp GameManager.h
	$(CC) -c main.cpp

GameManager.o: GameManager.cpp GameManager.h CommandHandler.h define.h User.h Film.h Publisher.h
	$(CC) -c GameManager.cpp

CommandHandler.o: CommandHandler.cpp CommandHandler.h define.h
	$(CC) -c CommandHandler.cpp

User.o: User.cpp User.h Publisher.h Film.h Comment.h
	$(CC) -c User.cpp

Publisher.o: Publisher.cpp Publisher.h User.h Film.h
	$(CC) -c Publisher.cpp

Film.o: Film.cpp Film.h Comment.h 
	$(CC) -c Film.cpp

Comment.o: Comment.cpp Comment.h
	$(CC) -c Comment.cpp

Exceptions.o: Exceptions.cpp Exceptions.h define.h
	$(CC) -c Exceptions.cpp

.PHONY: clean
clean:
	rm *.o
	rm a.out