CC				= cc 
RM				= rm -f
CFLAGS			= -Wextra -Wall -Werror
PUSH_SWAP_NAME 	= push_swap
PUSH_SWAP_SRCS	= src/push_swap.c src/push_swap_utils.c src/parsing.c src/push.c src/rotate.c src/reverse_rotate.c src/swap.c src/sort_three.c src/sort_numbers.c src/sort_utils.c src/sort_big_utils.c \
				  printf/ft_printf.c printf/nbrs.c printf/puts.c
PUSH_SWAP_OBJS 	= $(PUSH_SWAP_SRCS:.c=.o)

BONUS_NAME = checker
BONUS_SRCS = bonus/checker.c bonus/checker_utils.c src/push_swap_utils.c src/parsing.c src/push.c src/rotate.c src/reverse_rotate.c src/swap.c src/sort_three.c src/sort_numbers.c src/sort_utils.c src/sort_big_utils.c \
			 printf/ft_printf.c printf/nbrs.c printf/puts.c \
			 get_next_line/get_next_line_utils.c get_next_line/get_next_line.c  
BONUS_OBJS 	= $(BONUS_SRCS:.c=.o)

all:			$(PUSH_SWAP_NAME)

$(PUSH_SWAP_NAME):	$(PUSH_SWAP_OBJS)
					$(CC) -o $(PUSH_SWAP_NAME) $(PUSH_SWAP_SRCS) $(CFLAGS)

$(BONUS_NAME):	$(BONUS_OBJS) $(PUSH_SWAP_OBJS)
				$(CC) -o $(BONUS_NAME) $(BONUS_SRCS) $(CFLAGS)

clean:
				$(RM) $(PUSH_SWAP_OBJS) $(BONUS_OBJS)
				 
fclean:	 		clean
				$(RM) $(PUSH_SWAP_NAME) $(BONUS_NAME)
				
re:				fclean all

bonus:			$(BONUS_NAME)

.PHONY:			all clean fclean re bonus