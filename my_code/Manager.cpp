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
    server.post("/signup", new SignupHandler(data));
    server.get("/passErr", new ShowPage("static/passErr.html"));
    server.get("/usernameErr", new ShowPage("static/usernameErr.html"));
    server.get("/login", new ShowPage("static/login.html"));
    server.post("/login", new LoginHandler(data));
    server.get("/loginPassErr", new ShowPage("static/loginPassErr.html"));
    server.post("/logout", new LogoutHandler());
    server.get("/home", new HomeHandler("template/home.html", data));
    server.post("/delete_films", new DeleteFilmHandler(data));
    server.post("/addFilm", new AddFilmHandler(data, recommender));
    // server.get("/profile", new homeHandler("template/home.html", data));
    // server.get("/filterFilms", new ShowPage("static/signup.html"));
    // server.get("/showDetails", new ShowPage("static/film_detailcss.html"));
    server.post("/increaseMoney", new IncreaseMoneyHandler(data));
    server.post("/addComment", new CommentHandler(data));
    server.post("/buy", new BuyHandler(data, recommender));
    server.post("/rate", new RateHandler(data));
    server.run();
  } catch (Server::Exception e) {
    cerr << e.getMessage() << endl;
  }
}