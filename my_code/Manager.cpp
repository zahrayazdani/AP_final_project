#include <iostream>
#include "Manager.h"
#include "../server/server.hpp"
#include "Data.h"
#include "Handlers.h"

using namespace std;

Manager::Manager()
{
    data = new Data;
}

//argc va argv
//not foundm toush benevise chi shode
//controller
//template pass va signup
//buttonam bkhan bran y ja

void Manager::run(int argc, char** argv)
{
	try {
    Server server(argc > 1 ? atoi(argv[1]) : 5000);
    server.setNotFoundErrPage("static/404.html");
    server.get("/", new ShowPage("static/firstPage.html"));
    server.get("/signup", new ShowPage("static/signup.html"));
    server.post("/signup", new signupHandler(data));
    server.get("/passErr", new ShowPage("static/passErr.html"));
    server.get("/usernameErr", new ShowPage("static/usernameErr.html"));
    server.get("/login", new ShowPage("static/login.html"));
    server.post("/login", new loginHandler());
    server.get("/loginPassErr", new ShowPage("static/loginPassErr.html"));
    server.post("/logout", new logoutHandler());
    // server.get("/delete_films", new ShowPage("static/delete_filmscss.html"));
    // server.post("/delete_films", new loginHandler());
    // server.get("/films", new ShowPage("static/add_filmcss.html"));
    // server.post("/films", new loginHandler());
    // server.get("/money", new ShowPage("static/increse_creditcss.html"));
    // server.post("/money", new loginHandler());
    // server.get("/films", new ShowPage("static/film_detailcss.html"));
    // server.post("/films", new loginHandler());
    // server.get("/comments", new ShowPage("static/commentscss.html"));
    // server.post("/comments", new loginHandler());
    // server.get("/buy", new ShowPage("static/buycss.html"));
    // server.post("/buy", new loginHandler());
    // server.get("/rate", new ShowPage("static/ratecss.html"));
    // server.post("/rate", new loginHandler());
    server.run();
  } catch (Server::Exception e) {
    cerr << e.getMessage() << endl;
  }
}