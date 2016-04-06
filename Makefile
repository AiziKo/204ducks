##
## Makefile for  in /home/frasse_l/Projets/204ducks
## 
## Made by loic frasse-mathon
## Login   <frasse_l@epitech.net>
## 
## Started on  Mon Mar 14 11:47:21 2016 loic frasse-mathon
## Last update Wed Apr  6 18:59:33 2016 loic frasse-mathon
##

CPP		= g++

CPPFLAGS	= -W -Wall -Werror -Wextra -I./include -g

SRC		= src/main.cpp \
		src/ducks.cpp

OBJ		= $(SRC:.cpp=.o)

NAME		= 204ducks

RM		= rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CPP) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
