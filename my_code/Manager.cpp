#include <iostream>
#include "Manager.h"
#include "../server/server.hpp"
#include "Data.h"
#include "Handlers.h"
#include "Recommender.h"

using namespace std;

Manager::Manager()
{
    data = new Data;
    recommender = new Recommender(data);
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
    server.get("/home", new homeHandler("template/home.html", data));
    server.post("/delete_films", new deleteFilmHandler(data));
    server.post("/addFilm", new addFilmHandler(data, recommender));
    // server.get("/profile", new homeHandler("template/home.html", data));
    // server.get("/filterFilms", new ShowPage("static/signup.html"));
    // server.get("/showDetails", new ShowPage("static/film_detailcss.html"));
    server.post("/increaseMoney", new increaseMoneyHandler(data));
    server.post("/addComment", new commentHandler(data));
    server.post("/buy", new buyHandler(data, recommender));
    server.post("/rate", new rateHandler(data));
    server.run();
  } catch (Server::Exception e) {
    cerr << e.getMessage() << endl;
  }
}