int	is_white_space(char c);

int	ft_atoi(char *str)
{
	int	neg;
	int	res;

	res = 0;
	neg = 1;
	while (is_white_space(*str) == 1)
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = neg * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{	
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * neg);
}

int	is_white_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f')
		return (1);
	else if (c == '\r')
		return (1);
	return (0);
}
