# LIBFT
SOURCES			= src/main.c \
				  src/init/init.c src/init/launch.c \
				  src/philo/time_utils.c \
				  src/philo/routine.c src/philo/print.c \
				  src/philo/logic/eat.c src/philo/logic/fork.c
OBJECTS     = ${SOURCES:.c=.o}
NAME        = philo
CC          = clang
FLAGS       = -Wall -Werror -Wextra -pthread -g
GREEN				= \033[92m
BLUE				= \033[94m
ORANGE			= \033[93m
RED					= \033[91m
WHITE				= \033[0m

all: libft_compile ${NAME}

title:
	@printf  "${BLUE}"
	@cat .title

libft_compile:
	make -C ./src/libft

${NAME}: ${OBJECTS}
	${CC} -g ${OBJECTS} -L./src/libft -lft -o ${NAME}
	@printf "${GREEN}\n\n✅ philo pret !\n"

%.o: %.c
	@${CC} ${FLAGS} -I./src/libft -c $< -o $@
	@printf  "\r${BLUE}✅ Compilation $< objects termine"

clean:
	@printf  "${ORANGE}⏳ Supression des objetcs philo\n"
	make -C ./src/libft clean
	@rm -rf ${OBJECTS}

fclean: clean
	@printf  "${ORANGE}⏳ Supression executale philo\n"
	make -C ./src/libft fclean
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
