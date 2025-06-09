.DELETE_ON_ERROR:
.DEFAULT_GOAL = all \

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME := ex00
SRCS := $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
-include $(DEPS)

ifdef DEPS
	CXXFLAGS += -MMD -MP
endif
ifdef DEBUG
	CXXFLAGS += -g3
endif
ifdef ADDRESS
	CXXFLAGS += -fsanitize=address
endif

all:
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re