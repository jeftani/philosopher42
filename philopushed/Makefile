
NAME	=	philo

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror 
RM		=	rm -f

SRCS	=	philosophers.c \
			src/ft_atoi.c \
			src/ft_init.c \
			src/ft_itoi_time.c \
			src/philo_eat.c \
			src/ft_to_die.c \
			src/ft_create_thread.c \
			src/ft_free_destroy.c \
			src/ft_limit_meals.c \

OBJS	=	$(SRCS:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "Linked into executable \033[0;32mphilo\033[0m."

clean:
			@$(RM) $(OBJS)
			@echo "Removed object files."

fclean:		clean
			@$(RM) $(NAME)
			@echo "Removed executable."

re:			fclean all

.PHONY:		all clean fclean re
