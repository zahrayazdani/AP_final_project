#ifndef MANAGER_H
#define MANAGER_H

class Data;

class Manager
{
private:
	Data* data;
public:
	Manager();
	// ~Manager();
	void run(int argc, char** argv);
};

#endif