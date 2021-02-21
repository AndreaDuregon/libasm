NAME	=	libasm.a

SRC		=	ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s

OBJ		=	$(SRC:.s=.o)

%.o		:	%.s
			nasm -f macho64 $< -o $@

$(NAME)	:	$(OBJ)
			ar rcs $(NAME) $(OBJ)

all		:	$(NAME)

test	:	all
			gcc -Wall -Wextra -Werror main.c libasm.a -o test
			./test

clean	:	$(OBJ)
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

testcl	:	fclean
			rm -f test

re		:	fclean all

.PHONY	:	all test clean fclean testcl re