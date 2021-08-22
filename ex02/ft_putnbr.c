#include <unistd.h>

void	ft_printChar(char c);

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_printChar(56);
	}
	else
	{
		if (nb < 0)
		{
			nb = -1 * nb;
			ft_printChar('-');
		}
		if (nb < 10)
		{
			ft_printChar(48 + nb);
		}
		else
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
	}
}

void	ft_printChar(char c)
{
	write(1, &c, 1);
}
