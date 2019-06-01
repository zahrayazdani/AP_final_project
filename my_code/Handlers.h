#ifndef HANDLERS_H
#define HANDLERS_H

#include "../server/server.hpp"

class signupHandler : public RequestHandler {
public:
  Response* callback(Request*);
};

#endif