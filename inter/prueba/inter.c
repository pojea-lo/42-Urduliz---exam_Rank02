#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(char *str);
char	*ft_check(char *str);
void	ft_check_dual(char *str1, char *str3);

int	main(int argc, char *argv[])
{
	char	*s1;
	char	*s2;

	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	else
	{
		s1 = ft_check (argv[1]);
		s2 = ft_check (argv[2]);
		ft_check_dual (s1, s2);
	}
	return (0);
}

char	*ft_check(char *str)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (j < ft_strlen(str))
		{
			if (str[i] == str[j])
			{
				k = j;
				while (j < ft_strlen(str))
				{
					str[j] = str[j + 1];
					j++;
				}
				str[j] = '\0';
				j = k;
			}
			else
				j++;
		}
		i++;
	}
	return (str);
}

void	ft_check_dual(char *str1, char *str2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str1[i] != '\0')
	{
		j = 0;
		while (str2[j] != '\0')
		{
			if (str1[i] == str2[j])
				write (1, &str1[i], 1);
			j++;
		}
		i++;
	}
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
