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

int	main(void)
{
	trim_tests();
}
