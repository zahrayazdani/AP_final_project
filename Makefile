CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build
TEMPLATE_DIR=.template

all: $(BUILD_DIR) myserver.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp
	$(CC) $(CF) -c utils/template_parser.cpp -o $(BUILD_DIR)/template_parser.o

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/main.o: my_code/main.cpp my_code/Manager.h
	$(CC) $(CF) -c my_code/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/Manager.o: my_code/Manager.cpp my_code/Manager.h my_code/Data.h my_code/Handlers.h my_code/Recommender.h
	$(CC) $(CF) -c my_code/Manager.cpp -o $(BUILD_DIR)/Manager.o

$(BUILD_DIR)/Handlers.o: my_code/Handlers.cpp my_code/Handlers.h server/server.hpp my_code/Data.h my_code/define.h my_code/User.h my_code/Publisher.h my_code/Film.h my_code/Recommender.h
	$(CC) $(CF) -c my_code/Handlers.cpp -o $(BUILD_DIR)/Handlers.o

$(BUILD_DIR)/Comment.o: my_code/Comment.cpp my_code/Comment.h
	$(CC) $(CF) -c my_code/Comment.cpp -o $(BUILD_DIR)/Comment.o

$(BUILD_DIR)/Data.o: my_code/Data.cpp my_code/Data.h my_code/define.h my_code/User.h my_code/Publisher.h my_code/Film.h
	$(CC) $(CF) -c my_code/Data.cpp -o $(BUILD_DIR)/Data.o

$(BUILD_DIR)/Film.o: my_code/Film.cpp my_code/Film.h my_code/define.h my_code/Comment.h
	$(CC) $(CF) -c my_code/Film.cpp -o $(BUILD_DIR)/Film.o

$(BUILD_DIR)/Publisher.o: my_code/Publisher.cpp my_code/Publisher.h my_code/define.h my_code/User.h my_code/Film.h my_code/Comment.h
	$(CC) $(CF) -c my_code/Publisher.cpp -o $(BUILD_DIR)/Publisher.o

$(BUILD_DIR)/Recommender.o: my_code/Recommender.cpp my_code/Recommender.h my_code/define.h my_code/User.h my_code/Film.h my_code/Data.h
	$(CC) $(CF) -c my_code/Recommender.cpp -o $(BUILD_DIR)/Recommender.o

$(BUILD_DIR)/User.o: my_code/User.cpp my_code/User.h my_code/define.h my_code/Publisher.h my_code/Film.h my_code/Comment.h
	$(CC) $(CF) -c my_code/User.cpp -o $(BUILD_DIR)/User.o

myserver.out: $(BUILD_DIR)/main.o $(BUILD_DIR)/Handlers.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o $(BUILD_DIR)/Manager.o $(BUILD_DIR)/Comment.o $(BUILD_DIR)/Data.o $(BUILD_DIR)/Film.o $(BUILD_DIR)/Publisher.o $(BUILD_DIR)/Recommender.o $(BUILD_DIR)/User.o  
	$(CC) $(CF) $(BUILD_DIR)/main.o $(BUILD_DIR)/Handlers.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o $(BUILD_DIR)/Manager.o  $(BUILD_DIR)/Comment.o $(BUILD_DIR)/Data.o $(BUILD_DIR)/Film.o $(BUILD_DIR)/Publisher.o $(BUILD_DIR)/Recommender.o $(BUILD_DIR)/User.o -o myserver.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TEMPLATE_DIR) *.o *.out &> /dev/null