#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

class Controller;
class Data;

class CommandHandler
{
private:
	Controller* controller;
public:
	CommandHandler(Data* data);
};

#endif