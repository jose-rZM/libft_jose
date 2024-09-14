#include "libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*s;
	char	*needle;
	char	*uwu;

	s = "hola mundo";
	needle = NULL;
	uwu = ft_strnstr(s, needle, 9);
	printf("%s", uwu);
}
