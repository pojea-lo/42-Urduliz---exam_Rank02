#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *s, ...);
size_t	ft_cases (char c, va_list ptr, size_t j);
size_t	ft_putstr (char *str, size_t j);
size_t	ft_putint (int	n, size_t j);

int	main(void)
{
	int	i;

	i = ft_printf ("Prueba: %s\n", "toto");
	printf("i = %d\n", i);
	i = ft_printf ("Magic %s is %d", "number", -2147483648);
	printf("\ni = %d\n", i);
/*	i = ft_printf ("Hexadecimal for %d id %x\n", 42, 42);
	printf("i = %d\n", i);*/
	return (0);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	size_t	j;
	va_list	ptr;

	i = 0;
	j = 0;
	va_start (ptr, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i])
		{
			i++;
			j = ft_cases (s[i], ptr, j);
		}
		else
		{
			write(1, &s[i], 1);
			j++;
		}
		i++;
	}
	va_end (ptr);
	return (j);
}

size_t	ft_cases (char c, va_list ptr, size_t j)
{
	if (c == 's')
		j = ft_putstr (va_arg (ptr, char *), j);
	else if (c == 'd')
		j = ft_putint (va_arg (ptr, int), j);
/*	else if (c == 'x')
		j = ft_puthex (va_arg (ptr, unsigned int), j);*/
	return (j);
}

size_t	ft_putstr (char *str, size_t j)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		j++;
		i++;
	}
	j--;
	return (j);
}

size_t	ft_putint (int	n, size_t j)
{
	char *dec;

	dec = "0123456789";

	if (n == -2147483648)
	{	
		j = j + write (1, "-2147483648", 11);
		return (j);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		j++;
	}
	if (n > 0)
	{
	j = ft_putint (n / 10, j);
	j = j + 1;
	write (1, &dec[n % 10], 1);
	}
	return (j);
}
