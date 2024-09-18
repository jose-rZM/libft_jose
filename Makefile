MANDATORY_PART 	   = ft_isalpha \
					 ft_isdigit \
					 ft_isalnum \
					 ft_isascii \
					 ft_isprint \
					 ft_strlen \
					 ft_memset \
					 ft_bzero \
					 ft_memcpy \
					 ft_memmove \
					 ft_strlcpy \
					 ft_strlcat \
					 ft_toupper \
					 ft_tolower \
					 ft_strchr \
					 ft_strrchr \
					 ft_strncmp \
					 ft_memchr \
					 ft_memcmp \
					 ft_strnstr \
					 ft_atoi \
					 ft_calloc \
					 ft_strdup \
					 ft_substr \
					 ft_strjoin \
					 ft_strtrim \
					 ft_split \
					 ft_itoa \
					 ft_strmapi \
					 ft_striteri \
					 ft_putchar_fd \
					 ft_putstr_fd \
					 ft_putendl_fd \
					 ft_putnbr_fd

BONUS_PART		= ft_lstnew \
				  ft_lstadd_front \
				  ft_lstsize \
				  ft_lstlast \
				  ft_lstadd_back \
				  ft_lstdelone \
				  ft_lstclear \
				  ft_lstiter \
				  ft_lstmap

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

LIB	= libft.a

SRCS	= $(MANDATORY_PART:%=%.c)
BONUS_SRCS = $(BONUS_PART:%=%.c)

OBJS	= $(MANDATORY_PART:%=%.o)
BONUS_OBJS = $(BONUS_PART:%=%.o)

NAME	= $(LIB)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS) -I./
	ar -rc $(LIB) $(OBJS)

all: $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -c $(SRCS) $(BONUS_SRCS) -I./
	ar -rc $(LIB) $(OBJS) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re so
