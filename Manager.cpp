#include <iostream>
#include "CommandHandler.h"
#include "Manager.h"
#include "User.h"
#include "Film.h"
#include "Publisher.h"
#include "define.h"

using namespace std;

Manager::Manager()
{
	command_handler = new CommandHandler;
	signup_id = FIRST_ID;
	film_id = FIRST_ID;
}

void Manager::run()
{
	
}