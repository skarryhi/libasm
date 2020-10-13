NAME = libasm.a
HEADER = libasm.h
CFLAGS = -Wall -Werror -Wextra

SRS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s ft_write.s ft_read.s

OBJ = ft_strlen.o ft_strcpy.o ft_strcmp.o ft_strdup.o ft_write.o ft_read.o

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rc $(NAME) $(OBJ)
	gcc main.c $(OBJ) -L. -lasm -o test

$(OBJ): %.o: %.s
	nasm -f macho64 -s $<

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME) test

re:		fclean all

.PHONY: all clean fclean re bonus norm cubnorm