#include <iostream>
#include "Exceptions.h"
#include "define.h"

using namespace std;

const char* NotFound::what() const throw()
{
	return NOTFOUND;
}

const char* BadRequest::what() const throw()
{
	return BADREQUEST;
}

const char* PermissionDenied::what() const throw()
{
	return PERMISSIONDENIED;
}