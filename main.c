#include "libft.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	test_atoi(const char *str)
{
	int	result_std;
	int	result_ft;

	result_std = atoi(str);
	result_ft = ft_atoi(str);
	printf("Testing: \"%s\"\n", str);
	printf("atoi: %d, ft_atoi: %d\n", result_std, result_ft);
	assert(result_std == result_ft);
}

void	atoi_tests(void)
{
	test_atoi("1234");  // Número positivo simple
	test_atoi("-1234"); // Número negativo simple
	test_atoi("+1234"); // Número positivo con signo explícito
	// Casos con espacios
	test_atoi("   1234");  // Espacios antes del número
	test_atoi("   -1234"); // Espacios antes de un número negativo
	test_atoi("   +1234"); // Espacios antes de un número positivo
	// Casos de cadenas no numéricas
	test_atoi("abc");     // Cadena no numérica
	test_atoi("1234abc"); // Número seguido de caracteres no numéricos
	test_atoi("abc1234"); // Cadena no numérica seguida de un número
	// Casos de límites
	test_atoi("2147483647");  // INT_MAX
	test_atoi("-2147483648"); // INT_MIN
	// Casos con cero
	test_atoi("0");    // Cero simple
	test_atoi("   0"); // Cero con espacios
	// Casos de números muy grandes o fuera de los límites
	test_atoi("999999999999999999999999999999999"); // Número fuera de rango
	test_atoi("-999999999999999999999999999999999");
}

void	substr_tests(void)
{
	char	*result;

	// Test 1: Cadena normal, dentro del rango
	result = ft_substr("Hello, World!", 7, 5);
	if (result && strcmp(result, "World") == 0)
		printf("Test 1 passed!\n");
	else
		printf("Test 1 failed: %s\n", result ? result : "NULL");
	free(result);
	// Test 2: Longitud mayor que la cadena restante
	result = ft_substr("Hello", 2, 10); // Espera: "llo"
	if (result && strcmp(result, "llo") == 0)
		printf("Test 2 passed!\n");
	else
		printf("Test 2 failed: %s\n", result ? result : "NULL");
	free(result);
	// Test 3: Inicio fuera del rango
	result = ft_substr("Hello", 10, 5); // Espera: NULL
	if (result && strcmp(result, "") == 0)
		printf("Test 3 passed!\n");
	else
		printf("Test 3 failed: %s\n", result);
	free(result);
	// Test 4: Longitud de subcadena es 0
	result = ft_substr("Hello", 2, 0); // Espera: ""
	if (result && strcmp(result, "") == 0)
		printf("Test 4 passed!\n");
	else
		printf("Test 4 failed: %s\n", result ? result : "NULL");
	free(result);
	// Test 5: Cadena vacía
	result = ft_substr("", 0, 5); // Espera: ""
	if (result && strcmp(result, "") == 0)
		printf("Test 5 passed!\n");
	else
		printf("Test 5 failed: %s\n", result ? result : "NULL");
	free(result);
	// Test 6: Longitud exacta hasta el final de la cadena
	result = ft_substr("Goodbye", 4, 3); // Espera: "bye"
	if (result && strcmp(result, "bye") == 0)
		printf("Test 6 passed!\n");
	else
		printf("Test 6 failed: %s\n", result ? result : "NULL");
	free(result);
	// Test 7: Start igual al largo de la cadena
	result = ft_substr("Test", 4, 2); // Espera: ""
	if (result && strcmp(result, "") == 0)
		printf("Test 7 passed!\n");
	else
		printf("Test 7 failed: %s\n", result ? result : "NULL");
	free(result);
	// Test 8: Cadena NULL (error)
	result = ft_substr(NULL, 0, 5); // Espera: NULL
	if (result == NULL)
		printf("Test 8 passed!\n");
	else
		printf("Test 8 failed: %s\n", result);
	free(result);
}

void	join_tests(void)
{
	char	*result;

	// Test 1: Unir dos cadenas normales
	result = ft_strjoin("Hola", " Mundo");
	if (result)
	{
		printf("Test 1: %s\n", result); // Resultado esperado: "Hola Mundo"
		free(result);
	}
	else
	{
		printf("Test 1: Error en la reserva de memoria\n");
	}
	// Test 2: Primera cadena vacía
	result = ft_strjoin("", " Mundo");
	if (result)
	{
		printf("Test 2: %s\n", result); // Resultado esperado: " Mundo"
		free(result);
	}
	else
	{
		printf("Test 2: Error en la reserva de memoria\n");
	}
	// Test 3: Segunda cadena vacía
	result = ft_strjoin("Hola", "");
	if (result)
	{
		printf("Test 3: %s\n", result); // Resultado esperado: "Hola"
		free(result);
	}
	else
	{
		printf("Test 3: Error en la reserva de memoria\n");
	}
	// Test 4: Ambas cadenas vacías
	result = ft_strjoin("", "");
	if (result)
	{
		printf("Test 4: %s\n", result); // Resultado esperado: ""
		free(result);
	}
	else
	{
		printf("Test 4: Error en la reserva de memoria\n");
	}
	// Test 5: Una cadena NULL
	result = ft_strjoin(NULL, " Mundo");
	if (result)
	{
		printf("Test 5: %s\n", result); // Resultado esperado: NULL
		free(result);
	}
	else
	{
		printf("Test 5: NULL correctamente manejado\n");
	}
	// Test 6: Ambas cadenas NULL
	result = ft_strjoin(NULL, NULL);
	if (result)
	{
		printf("Test 6: %s\n", result); // Resultado esperado: NULL
		free(result);
	}
	else
	{
		printf("Test 6: NULL correctamente manejado\n");
	}
}

void	trim_tests(void)
{
	char	*result;

	// Test 1: Eliminar caracteres desde ambos extremos
	result = ft_strtrim("**$hola*", "*$");
	if (result)
	{
		printf("Test 1: %s\n", result); // Resultado esperado: "hola"
		free(result);
	}
	else
	{
		printf("Test 1: Error en la reserva de memoria\n");
	}
	// Test 2: Sin caracteres para eliminar
	result = ft_strtrim("hola", "*$");
	if (result)
	{
		printf("Test 2: %s\n", result); // Resultado esperado: "hola"
		free(result);
	}
	else
	{
		printf("Test 2: Error en la reserva de memoria\n");
	}
	// Test 3: Eliminar todos los caracteres
	result = ft_strtrim("****", "*");
	if (result)
	{
		printf("Test 3: %s\n", result); // Resultado esperado: ""
		free(result);
	}
	else
	{
		printf("Test 3: Error en la reserva de memoria\n");
	}
	// Test 4: Cadena vacía
	result = ft_strtrim("", "*$");
	if (result)
	{
		printf("Test 4: %s\n", result); // Resultado esperado: ""
		free(result);
	}
	else
	{
		printf("Test 4: Error en la reserva de memoria\n");
	}
	// Test 5: Set vacío (no elimina nada)
	result = ft_strtrim("hola", "");
	if (result)
	{
		printf("Test 5: %s\n", result); // Resultado esperado: "hola"
		free(result);
	}
	else
	{
		printf("Test 5: Error en la reserva de memoria\n");
	}
	// Test 6: Cadena NULL
	result = ft_strtrim(NULL, "*$");
	if (result)
	{
		printf("Test 6: %s\n", result); // Resultado esperado: NULL
		free(result);
	}
	else
	{
		printf("Test 6: NULL correctamente manejado\n");
	}
	// Test 7: Set NULL (no elimina nada)
	result = ft_strtrim("**$hola*", NULL);
	if (result)
	{
		printf("Test 7: %s\n", result); // Resultado esperado: "**$hola*"
		free(result);
	}
	else
	{
		printf("Test 7: Error en la reserva de memoria\n");
	}
	// Test 8: Cadena y set NULL
	result = ft_strtrim(NULL, NULL);
	if (result)
	{
		printf("Test 8: %s\n", result); // Resultado esperado: NULL
		free(result);
	}
	else
	{
		printf("Test 8: NULL correctamente manejado\n");
	}
}

void	print_split_result(char **result)
{
	int	i;

	if (result)
	{
		i = 0;
		while (result[i])
		{
			printf("Palabra %d: %s\n", i + 1, result[i]);
			free(result[i]); // Liberar cada palabra
			i++;
		}
		free(result); // Liberar el array de punteros
	}
	else
	{
		printf("Error en la reserva de memoria\n");
	}
}

void	split_tests(void)
{
	char	**result;

	// Test 1: Cadena con palabras separadas por un delimitador
	result = ft_split("hola,que,tal", ',');
	printf("Test 1:\n");
	print_split_result(result); // Resultado esperado: "hola", "que", "tal"
	// Test 2: Cadena con delimitadores consecutivos
	result = ft_split("hola,,que,,tal", ',');
	printf("Test 2:\n");
	print_split_result(result); // Resultado esperado: "hola", "que", "tal"
	// Test 3: Cadena que empieza y termina con delimitadores
	result = ft_split(",hola,que,tal,", ',');
	printf("Test 3:\n");
	print_split_result(result); // Resultado esperado: "hola", "que", "tal"
	// Test 4: Cadena sin el delimitador
	result = ft_split("holaquetal", ',');
	printf("Test 4:\n");
	print_split_result(result); // Resultado esperado: "holaquetal"
	// Test 5: Cadena vacía
	result = ft_split("", ',');
	printf("Test 5:\n");
	print_split_result(result); // Resultado esperado: NULL o array vacío
	// Test 6: Solo delimitadores
	result = ft_split(",,,", ',');
	printf("Test 6:\n");
	print_split_result(result); // Resultado esperado: NULL o array vacío
	// Test 7: Delimitador no presente en la cadena
	result = ft_split("holaquetal", ';');
	printf("Test 7:\n");
	print_split_result(result); // Resultado esperado: "holaquetal"
	// Test 8: Cadena NULL
	result = ft_split(NULL, ',');
	printf("Test 8:\n");
	print_split_result(result);
	// Test 9: Delimitador NULL (no válido en C,
		pero puede probarse como caso extremo)
	result = ft_split("holaquetal", '\0');
	printf("Test 9:\n");
	print_split_result(result); // Resultado esperado: "holaquetal"
}

int	main(void)
{
	split_tests();
}
