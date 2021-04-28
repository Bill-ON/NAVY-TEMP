##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=	navy

TESTS		=	unit_test

CC		=	gcc

RM		=	rm -f

GCOVR		=	gcovr

LIB		=	-L./lib/my -lmy

INC		=	-I./include

CRIT		=	-lcriterion

COVER		=	--coverage

BRANCH		=	--branches

EXCLUD		=	--exclude

CPPFLAGS 	=	$(INC) -Wall -Wextra

SRC_DIR		=	src/

LIB_DIR		=	lib/my/

TESTS_DIR	=	tests/

OBJ		=	$(SRC:.c=.o)

UNIT_TEST	=	$(TESTS_DIR)tests_my_cipher.c			\

SRC		=	$(SRC_DIR)main.c	\
			$(SRC_DIR)init_grid.c	\

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	$(CC) -g3 -o $(NAME) $(OBJ) $(LIB) -lm

unit_tests:
	$(MAKE) -C lib/my
	$(CC) -o $(TESTS) $(UNIT_TEST) $(LIB) $(INC) $(COVER) $(CRIT)

run_tests: unit_tests
	./unit_test
	$(GCOVR) $(EXCLUD) $(TESTS_DIR)
	$(GCOVR) $(EXCLUD) $(TESTS_DIR) $(BRANCH)

clean:
	$(MAKE) -C lib/my clean
	$(RM) $(OBJ) *gc*

fclean:	clean
	$(MAKE) -C lib/my fclean
	$(RM) $(NAME) $(TESTS)

re:	fclean all

.PHONY: all tests fclean re
