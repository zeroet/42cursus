#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_check(char *str, char c, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (str[j] == c)
			return (0);
		++j;
	}
	return (1);
}

void	ft_inter(char *str, char *str2)
{
	int i
	int j;

	i = 0;
	while (str[i])
	{
		if (ft_check(str, str[i], i) == 1)
			j = 0;
			while (str2[j])
			{
				if (str2[j]==str[i])
				{
					write(1, &str[i], 1);
					break;
				}
				++j;
			}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
		ft_inter(av[1],av[2]);
	write(1, "\n", 1);
	return (0);
}
