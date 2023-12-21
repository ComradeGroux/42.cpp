# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 22:39:25 by vgroux            #+#    #+#              #
#    Updated: 2023/12/21 21:28:49 by vgroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREENGREEN = \033[38;5;46m
RED = \033[0;31m
GREY = \033[38;5;240m
RESET = \033[0m

NAME =     PmergeMe

CC =         c++
CFLAGS =     -Wall -Wextra -Werror -std=c++98 -pedantic
RM =         rm -rf

DIR_S = srcs/
DIR_O = objs/
DIR_H = headers/
DIR_T = templates/

SRCS_LST =	main.cpp \
			PmergeMe.class.cpp
SRCS =		${addprefix ${DIR_S}, ${SRCS_LST}}
OBJS =		${SRCS:${DIR_S}%.cpp=${DIR_O}%.o}

HDRS_LST = PmergeMe.class.hpp
HDRS = ${addprefix ${DIR_H}, ${HDRS_LST}}

TMPLT_LST = 
TMPLTS = ${addprefix ${DIR_T}, ${TMPLT_LST}}

${NAME}: ${OBJS} ${HDRS} ${TMPLTS}
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: ${NAME} objects were created${GREY}"
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: ${NAME} created !"

all: ${NAME}

${DIR_O}%.o:${DIR_S}%.cpp
	@printf "${GREY}"
	@mkdir -p ${DIR_O}
	${CC} ${CFLAGS} -I ${DIR_H} -I ${DIR_T} -o $@ -c $<

clean:
	@echo "[$(RED)${NAME}$(RESET)]: cleaning ${NAME} objects...${GREY}"
	${RM} ${OBJS}
	${RM} ${DIR_O}
	${RM} ${DIR_SAN}
	@echo "[$(RED)${NAME}$(RESET)]: ${NAME} objects were cleaned${GREY}"

fclean: clean
	@echo "${RESET}[$(RED)${NAME}$(RESET)]: cleaning ${NAME}...${GREY}"
	${RM} ${NAME}
	@echo "${RESET}[$(RED)${NAME}$(RESET)]: ${NAME} executable was cleaned"

printcompil:
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: ${NAME} objects compilation...${GREY}"

re: fclean printcompil all

.PHONY: all clean fclean re