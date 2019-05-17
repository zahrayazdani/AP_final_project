CC := g++ -std=c++11

all: a.out

a.out: main.o CommandHandler.o Comment.o Exceptions.o Film.o Manager.o Publisher.o User.o Controller.o Data.o Notification.o
	$(CC) -o a.out main.o CommandHandler.o Comment.o Exceptions.o Film.o Manager.o Publisher.o User.o Data.o Notification.o

main.o: main.cpp Manager.h
	$(CC) -c main.cpp

Manager.o: Manager.cpp Manager.h CommandHandler.h define.h User.h Film.h Publisher.h
	$(CC) -c Manager.cpp

CommandHandler.o: CommandHandler.cpp CommandHandler.h define.h
	$(CC) -c CommandHandler.cpp

User.o: User.cpp User.h Publisher.h Film.h Comment.h
	$(CC) -c User.cpp

Publisher.o: Publisher.cpp Publisher.h User.h Film.h Exceptions.h define.h
	$(CC) -c Publisher.cpp

Film.o: Film.cpp Film.h Comment.h Exceptions.h
	$(CC) -c Film.cpp

Comment.o: Comment.cpp Comment.h
	$(CC) -c Comment.cpp

Exceptions.o: Exceptions.cpp Exceptions.h define.h
	$(CC) -c Exceptions.cpp

Controller.o: Controller.cpp Controller.h
	$(CC) -c Controller.cpp

Data.o: Data.cpp Data.h
	$(CC) -c Data.cpp

Notification.o: Notification.cpp Notification.h
	$(CC) -c Notification.cpp

.PHONY: clean
clean:
	rm *.o
	rm a.out