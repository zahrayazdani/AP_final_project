#ifndef MANAGER_H
#define MANAGER_H

class Data;
class Recommender;

class Manager
{
private:
	Data* data;
	Recommender* recommender;
public:
	Manager();
	// ~Manager();
	void run(int argc, char** argv);
};

#endif