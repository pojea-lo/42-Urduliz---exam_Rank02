#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

size_t	ft_puthex (unsigned int n, size_t j)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 15)
		j = ft_puthex(n/16, j);
	j++;
	write (1, &hex[n%16], 1);
	return (j);
}


size_t	ft_putint (int n, size_t j)
{
	char	*dec;

	dec = "0123456789";
	if (n == -2147483648)
	{
		j = j + write (1, "-2147483648", 11);
		return (j);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		j++;
		n = -n;
	}
	if (n > 9)
		j = ft_putint(n/10, j);
	j++;
	write (1, &dec[n%10], 1);
	return (j);
}

size_t	ft_putstr (char *s, size_t j)
{
	size_t	i;

	i = 0;
	while (s[i] != 00)
	{
		write (1, &s[i], 1);
		j++;
		i++;
	}
	return (j);
}

size_t	ft_cases(char c, va_list ptr, size_t j)
{
	if (c == 's')
		j = ft_putstr (va_arg(ptr, char *), j);
	else if (c == 'd')
		j = ft_putint (va_arg(ptr, int), j);
	else if (c == 'x')
		j = ft_puthex (va_arg(ptr, unsigned int), j);
	return (j);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	va_start(ptr, s);
	while (s[i] != 00)
	{
		if (s[i] == '%')
		{
			i++;
			j = ft_cases (s[i], ptr, j);
		}
		else
			j = j + write (1, &s[i], 1);
		i++;
	}
	va_end (ptr);
	return (j);
}

int	main(void)
{
	int	i;

	i = ft_printf("%s\n", "toto");
	printf("la i- %d\n", i);
	i = printf("%s\n", "toto");
	printf("la i- %d\n", i);
	i = ft_printf("Magic %s is %d\n", "number", 42);
	printf("la i- %d\n", i);
	i = printf("Magic %s is %d\n", "number", 42);
	printf("la i- %d\n", i);
	i = ft_printf("Hexadecimal for %d is %x\n", 42, 0);
	printf("la i- %d\n", i);
	i = printf("Hexadecimal for %d is %x\n", 42, 0);
	printf("la i- %d\n", i);
	return (0);
}
