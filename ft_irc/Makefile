NAME = ircserv

SRCS = Server.cpp main.cpp User.cpp Utils.cpp Channel.cpp Command.cpp

CXX = c++

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
