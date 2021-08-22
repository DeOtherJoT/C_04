#include <unistd.h>
int		str_len(char *str);

void	print_char(char c);

int		verify_ret_base(char *base);

void	put_nbr(int nbr, int radix, char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	int	radix;

	radix = verify_ret_base(base);
	if (radix != 1)
	{
		put_nbr(nbr, radix, base);
	}
	return ;
}

int	verify_ret_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0')
		return (1);
	while (base[i])
	{
		j = 1;
		if (base[i] <= ' ' || base[i] > '~')
			return (1);
		if (base[i] == '+' || base[i] == '-')
			return (1);
		while (base[i + j])
		{
			if (base[i] == base[i + j])
				return (1);
			j++;
		}
		i++;
	}
	return (i);
}

void	print_char(char c)
{
	write(1, &c, 1);
}

void	put_nbr(int nbr, int radix, char *base)
{
	unsigned int	n;

	if (nbr < 0)
	{
		n = nbr * -1;
		write (1, "-", 1);
	}
	n = nbr;
	if (n >= (unsigned int)radix)
	{
		put_nbr(n / radix, radix, base);
	}
	print_char(base[n % radix]);
}
