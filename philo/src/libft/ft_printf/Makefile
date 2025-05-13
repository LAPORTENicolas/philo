SOURCES = ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_puthex_fd.c ft_putnbr_fd.c
OBJECTS = ${SOURCES:.c=.o}
NAME 		= ft_printf.a
CC 			= cc
FLAGS 	= -Wall -Wextra -Werror
OBJECTS = ${SOURCES:.c=.o}
CC      = cc
FLAGS   = -Wall -Werror -Wextra
LIBFT   = libft/
MLX     = mlx/
GREEN   = \033[92m
BLUE    = \033[94m
ORANGE  = \033[93m
RED     = \033[91m
BOLD		= \033[1m
WHITE   = \033[0m

all: ${NAME}

${NAME}: ${OBJECTS}
	@ar -crs ${NAME} ${OBJECTS}
	@printf "\n${GREEN}✅ Compilation ${BOLD}${NAME}${WHITE}${GREEN} Termine !\n"; \

%.o: %.c
	@${CC} ${FLAGS} -c $< -o $@
	printf "${BLUE}\r⏳ Compilation ${BOLD}$< ${WHITE}${BLUE}to ${BOLD}$@${WHITE}${BLUE}"; \

clean:
	@rm -rf ${OBJECTS}
	@printf "${ORANGE}🗑️ Clean ${BOLD}${OBJECTS}\n${WHITE}"; \

fclean: clean
	@rm -rf ${NAME}
	@printf "${RED}🗑️ Clean ${BOLD}${NAME}\n${WHITE}"; \

re: fclean all

.PHONY: all clean re fclean
