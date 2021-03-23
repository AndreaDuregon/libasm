NAME	=	libasm.a

SRC		=	ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s \
			ft_list_size_bonus.s \
			ft_list_push_front_bonus.s \
			ft_list_sort_bonus.s \
			ft_list_remove_if_bonus.s 

OBJ		=	$(SRC:.s=.o)

%.o		:	%.s
			nasm -f macho64 $< -o $@

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			ar rcs $(NAME) $(OBJ)


test	:	all
			gcc main.c libasm.a -o test
			./test

bonus	:	all

clean	:	$(OBJ)
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

testcl	:	fclean
			rm -f test

re		:	fclean all

.PHONY	:	all test clean fclean testcl re