CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c print_int.c print_hex_pointer.c

#Dollar sign $ is used to reference the value of a variable. 
#For example, $(NAME) refers to the value of the NAME variable
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
# PROG = printf

all: $(NAME) 
# $(PROG)

#Ausfuehrbare Datei erstellen --> libft_makefile
#Percent sign % is used in pattern rules to represent a wildcard that matches part of a filename. 
#It is used in conjunction with the $ sign for variable substitution.
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# $(PROG): $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) -o printf

#loescht Objektdateien
clean:
	rm -f $(OBJ)

#loescht Objektdateien + ausfuehbare dateien 
fclean: clean
	rm -f $(NAME)

#rebuild 
re: fclean all