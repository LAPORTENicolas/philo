# LIBFT
SOURCES			= src/main.c src/init.c src/time_utils.c \
							src/philo/routine.c src/philo/utils.c
OBJECTS     = ${SOURCES:.c=.o}
NAME        = philo
CC          = clang
FLAGS       = -Wall -Werror -Wextra -pthread -O2 
GREEN				= \033[92m
BLUE				= \033[94m
ORANGE			= \033[93m
RED					= \033[91m
WHITE				= \033[0m

all: ${NAME}

title:
	@printf  "${BLUE}"
	@cat .title

${NAME}: ${OBJECTS}
	${CC} -g ${OBJECTS} -L./src/libft -lft -o ${NAME}
	@printf "${GREEN}\n\n✅ philo pret !\n"

%.o: %.c
	@${CC} ${FLAGS} -I./src/libft -c $< -o $@
	@printf  "\r${BLUE}✅ Compilation $< objects termine"

clean:
	@printf  "${ORANGE}⏳ Supression des objetcs philo\n"
	@rm -rf ${OBJECTS}

fclean: clean
	@printf  "${ORANGE}⏳ Supression executale philo\n"
	@rm -rf ${NAME}

reset: fclean
	@printf  "${ORANGE}⏳ Supression des object + executale philo\n"
	@rm -rf ${OBJECTS}
	@rm -rf ${NAME}
	@printf  "${GREEN}✅ Supression termine\n\n"

re: reset all

.PHONY: all clean fclean re
