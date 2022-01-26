#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	i;

	i = ft_printf ("%s\n", "toto");
	printf("i = \d\n", i);
	i = ft_printf ("Magic %s is %d", "number", 42);
	printf("i = \d\n", i);
	i = ft_printf ("Hexadecimal for %d id %x\n", 42, 42);
	printf("i = \d\n", i);
	return (0);
