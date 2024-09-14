#include "libft.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

int	main(void)
{
   char *s = "hola mundo";
    char *dup = ft_strdup(s);
    printf("original: %s\ndup: %s\n", s, dup);
    free(dup);
}
