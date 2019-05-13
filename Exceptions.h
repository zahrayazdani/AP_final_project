#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class NotFound : public std::exception
{
public:
	virtual const char* what() const throw();
};

class BadRequest : public std::exception
{
public:
	virtual const char* what() const throw();
};

class PermissionDenied : public std::exception
{
public:
	virtual const char* what() const throw();
};

#endif