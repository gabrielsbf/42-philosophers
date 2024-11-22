NAME = philo

RM = rm -rf

COMPILER = cc -Wall -Wextra -Werror -pthread

DIR_OBJS = builds/

DIR_SRCS = srcs/

GET_SRCS = $(shell find $(DIR_SRCS))

PRE-FILTER_SRCS = $(filter %.c, $(GET_SRCS))

INCLUDE_FD = includes/

FILTER_SRCS = $(filter-out %testing.c, $(PRE-FILTER_SRCS))

OBJS = $(FILTER_SRCS:%.c=$(DIR_OBJS)/%.o)

#NUMBERS = $(PHILOS) $(DIE) $(EAT) $(SLEEP) 7

#NUMBERS					=	1 800 200 200   # The philosopher should not eat and should die
#NUMBERS					=	5 800 200 200   # No philosopher should die.
#NUMBERS					=	5 900 200 200 7 # No philosopher should die.
#NUMBERS					=	4 410 200 200   # No philosopher should die.
#NUMBERS					=	4 310 200 100 7 # One philosopher should die.

#NUMBERS					=	4 10 200 100	#One philosopher should die

#NUMBERS					=	5 410 200 100 7 # One philosopher should die.
#NUMBERS					=	5 120 80 80 	# Moana tolds all will die
#NUMBERS					=	2 200 50 50 1
#NUMBERS					=	50 1000 60 60 1
#NUMBERS					=	2 110 50 50 2

#NUMBERS					=	4 200 205 200	# One should die
#NUMBERS					=	4 410 200 200 10	# No one should die. Stop after 10
#NUMBERS					=	-5 600 200 200	# ERROR - CRASH
#NUMBERS					=	5 -5 200 200	# ERROR - CRASH
#NUMBERS					=	4 600 -5 200	# ERROR - CRASH
#NUMBERS					=	5 600 200 -5	# ERROR - CRASH
#NUMBERS					=	4 600 200 200 -5	# ERROR - CRASH
#NUMBERS					=	5 600 150 150	# No one should die
#NUMBERS					=	4 410 200 200	# No one should die
#NUMBERS					=	100 800 200 200	# No one should die
NUMBERS					=	105 800 200 200	# No one should die

all: $(NAME)

$(NAME): $(OBJS) $(DIR_OBJS)
		$(COMPILER) $(OBJS) -o $(NAME)

$(DIR_OBJS):
		mkdir builds

$(DIR_OBJS)/%.o : %.c
		mkdir -p $(dir $@)
		$(COMPILER) -c $< -o $@ -I $(INCLUDE_FD)


val: all
		valgrind --read-inline-info=yes --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes ./$(NAME)
clean:
		$(RM) $(DIR_OBJS)

fclean: clean
		$(RM) $(NAME) $(DIR_OBJS)

re: fclean all

debug: COMPILER += -ggdb3
debug : fclean $(NAME)
