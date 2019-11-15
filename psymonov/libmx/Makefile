NLIB = libmx.a

INC = inc/libmx.h

HDR = libmx.h

SRC = mx_printchar.c mx_strlen.c mx_printstr.c mx_printint.c mx_strcmp.c mx_strnew.c mx_strcpy.c mx_strdup.c \
mx_strdel.c mx_get_char_index.c mx_strndup.c mx_strncpy.c mx_count_words.c mx_strsplit.c mx_file_to_str.c \
mx_create_node.c mx_push_back.c mx_printerr.c mx_text_check.c mx_isalpha.c mx_isdigit.c mx_atoi.c \
mx_arr_of_words.c mx_edge_matrix.c mx_create_graph.c mx_create_edge.c mx_find_paths.c mx_find_short_path.c \
mx_print_paths.c mx_sort_paths.c mx_isspace.c mx_itoa.c

SRCS = src/mx_printchar.c src/mx_strlen.c src/mx_printstr.c src/mx_printint.c src/mx_strcmp.c src/mx_strnew.c src/mx_strcpy.c src/mx_strdup.c \
src/mx_strdel.c src/mx_get_char_index.c src/mx_strndup.c src/mx_strncpy.c src/mx_count_words.c src/mx_strsplit.c src/mx_file_to_str.c \
src/mx_create_node.c src/mx_push_back.c src/mx_printerr.c src/mx_text_check.c src/mx_isalpha.c src/mx_isdigit.c src/mx_atoi.c src/mx_arr_of_words.c \
src/mx_edge_matrix.c src/mx_create_graph.c src/mx_create_edge.c src/mx_find_paths.c  src/mx_find_short_path.c src/mx_print_paths.c src/mx_sort_paths.c \
src/mx_isspace.c src/mx_itoa.c

OBJ = mx_printchar.o mx_strlen.o mx_printstr.o mx_printint.o mx_strcmp.o mx_strnew.o mx_strcpy.o mx_strdup.o mx_strdel.o mx_get_char_index.o \
mx_strndup.o mx_strncpy.o mx_count_words.o mx_strsplit.o mx_file_to_str.o mx_create_node.o mx_push_back.o mx_printerr.o mx_text_check.o \
mx_isalpha.o mx_isdigit.o mx_atoi.o mx_arr_of_words.o mx_edge_matrix.o mx_create_graph.o mx_find_paths.o mx_create_edge.o mx_find_short_path.o \
mx_print_paths.o mx_sort_paths.o mx_isspace.o mx_itoa.o

OBJO = obj/mx_printchar.o obj/mx_strlen.o obj/mx_printstr.o obj/mx_printint.o obj/mx_strcmp.o obj/mx_strnew.o obj/mx_strcpy.o obj/mx_strdup.o \
obj/mx_strdel.o obj/mx_get_char_index.o obj/mx_strndup.o obj/mx_strncpy.o obj/mx_count_words.o obj/mx_strsplit.o obj/mx_file_to_str.o \
obj/mx_create_node.o obj/mx_push_back.o obj/mx_printerr.o obj/mx_text_check.o obj/mx_isalpha.o obj/mx_isdigit.o obj/mx_atoi.o obj/mx_arr_of_words.o \
obj/mx_edge_matrix.o obj/mx_create_graph.o obj/mx_find_paths.o obj/mx_create_edge.o obj/mx_find_short_path.o obj/mx_print_paths.o obj/mx_sort_paths.o \
obj/mx_isspace.o obj/mx_itoa.o

CFLAG = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install clean

install:
	@mkdir obj
	@cp $(INC) $(SRCS) .
	@clang $(CFLGS) -c $(SRC) -I $(HDR)
	@mv $(OBJ) ./obj
	@ar -rc $(NLIB) $(OBJO)

uninstall:
	@rm -rf $(NLIB)

clean: 
	@rm -rf $(SRC) $(HDR)
	@rm -rf ./obj

reinstall: uninstall all
