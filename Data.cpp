#include "Data.h"
#include "define.h"
#include "User.h"
#include "Film.h"
#include "Publisher.h"

using namespace std;

Data::Data()
{
	signup_id = FIRST_ID;
	film_id = FIRST_ID;
	active_user = NULL;
}