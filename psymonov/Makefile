NAME = pathfinder

NLIB = libmx/libmx.a

INC = inc/libmx.h

HDR = libmx.h

SRC = mx_pathfinder.c

SRCS = src/mx_pathfinder.c

OBJ = mx_pathfinder.o

OBJO = obj/mx_pathfinder.o

CFLAG = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install clean

install:
	@cd libmx && make -f Makefile install
	@cp $(INC) $(SRCS) .
	@clang $(CFLAG) -c $(SRC) -I $(HDR)
	@mkdir obj
	@mv $(OBJ) ./obj
	@clang $(CFLAG) $(OBJO) $(NLIB) -o $(NAME)

uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(NAME)

clean: 
	@cd libmx && make -f Makefile clean
	@rm -rf $(SRC) $(HDR)
	@rm -rf ./obj

reinstall: uninstall all
