#include <iostream>
#include "CommandHandler.h"
#include "GameManager.h"
#include "User.h"
#include "Film.h"
#include "Publisher.h"
#include "define.h"

using namespace std;

GameManager::GameManager()
{
	command_handler = new CommandHandler;
}

void GameManager::run()
{
	
}