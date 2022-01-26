#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(char *s);

int	main(void)
{
	char	s1[] = "abacd22";			//con esta opcion falla el control de nulos
	char	s2[] = "aaa3dddr2aaamma";
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

/*	char	*s1;						//con esta opción falla la transferencia de posiciones
	char	*s2;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	s1 = "abacd22";
	s2 = "aaa3dddr2aaamma";*/

	i = 0;
	if (s1 == NULL || s2 == NULL)
	{
		write (1, "\n", 1);
		return (0);
	}
	while (s1[i] != '\0')
	{
		j = i + 1;
		l = ft_strlen(s1);
		while (j < l)
		{
			if (s1[i] == s1[j])
			{
				l = ft_strlen(s1);
				k = j;
				while (j < l)
				{
					s1[j] = s1[j + 1];
					j++;
				}
				s1[j] = '\0';
				j = k;
			}
			else
				j++;
		}
		i++;
	}
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		l = ft_strlen (s2);
		while (j < l)
		{
			if (s1[i] == s2[j])
			{
				l = ft_strlen (s2);
				k = j;
				while (j < l)
				{
					s2[j] = s2[j + 1];
					j++;
				}
				s2[j] = '\0';
				j = k;
				l--;
			}
			else
				j++;
		}
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		j = i + 1;
		l = ft_strlen (s2);
		while (j < l)
		{
			if (s2[i] == s2[j])
			{
				l = ft_strlen(s2);
				k = j;
				while (j < l)
				{
					s2[j] = s2[j + 1];
					j++;
				}
				s2[j] = '\0';
				j = k;
			}
			else
				j++;
		}
		i++;
	}
	printf ("%s\n", s1);
	printf ("%s\n", s2);
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
