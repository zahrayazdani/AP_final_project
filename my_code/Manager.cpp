#include <iostream>
#include "Manager.h"
#include "../server/server.hpp"

using namespace std;

Manager::Manager()
{
	
}

//argc va argv
//not foundm toush benevise chi shode
void Manager::run(int argc, char** argv)
{
	try {
    Server server(argc > 1 ? atoi(argv[1]) : 5000);
    // server.setNotFoundErrPage("static/404.html");
    // server.get("/", new ShowPage("static/home.html"));
    server.get("/signup", new ShowPage("static/signup.html"));
    server.post("/signup", new SingupHandler());
    // server.get("/login", new ShowPage("static/logincss.html"));
    // server.post("/login", new LoginHandler());
    // server.get("/logout", new ShowPage("static/logoutcss.html"));
    // server.post("/logout", new LoginHandler());
    // server.get("/delete_films", new ShowPage("static/delete_filmscss.html"));
    // server.post("/delete_films", new LoginHandler());
    // server.get("/films", new ShowPage("static/add_filmcss.html"));
    // server.post("/films", new LoginHandler());
    // server.get("/money", new ShowPage("static/increse_creditcss.html"));
    // server.post("/money", new LoginHandler());
    // server.get("/films", new ShowPage("static/film_detailcss.html"));
    // server.post("/films", new LoginHandler());
    // server.get("/comments", new ShowPage("static/commentscss.html"));
    // server.post("/comments", new LoginHandler());
    // server.get("/buy", new ShowPage("static/buycss.html"));
    // server.post("/buy", new LoginHandler());
    // server.get("/rate", new ShowPage("static/ratecss.html"));
    // server.post("/rate", new LoginHandler());
    server.run();
  } catch (Server::Exception e) {
    cerr << e.getMessage() << endl;
  }
}