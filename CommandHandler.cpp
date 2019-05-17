#include "CommandHandler.h"
#include "Controller.h"
#include "Data.h"

CommandHandler::CommandHandler(Data* data)
{
	controller = new Controller(data);
}