int	str_len(char *str);

int	is_white_space(char c);

int	is_base_valid(char *base);

int	return_unique_char(char *base, char c);

int	ft_atoi_base(char *str, char *base)
{
	int	neg;
	int	res;
	int	radix;

	res = 0;
	neg = 1;
	if (is_base_valid(base) == 0)
		return (0);
	radix = str_len(base);
	while (is_white_space(*str) == 1)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (return_unique_char(base, *str) != -1)
	{
		res *= radix;
		res += return_unique_char(base, *str);
		str++;
	}
	return (res * neg);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_white_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f')
		return (1);
	else if (c == '\r')
		return (1);
	return (0);
}

int	is_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0' || str_len(base) == 1)
		return (0);
	while (base[i])
	{
		if (is_white_space(base[i]) == 1)
			return (0);
		else if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 1;
		while (base[i + j])
		{
			if (base[i] == base[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	return_unique_char(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
