#include <unistd.h>

void	printChar(char c);

void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		printChar(c[i]);
		i++;
	}
}

void	printChar(char c)
{
	write(1, &c, 1);
}
