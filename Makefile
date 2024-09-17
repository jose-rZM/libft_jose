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
					 ft_putchar_fd

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

LIB	= libft.a

SRCS	= $(MANDATORY_PART:%=%.c)

OBJS	= $(MANDATORY_PART:%=%.o)

NAME	= $(LIB)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS) -I./
	ar -rc $(LIB) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
