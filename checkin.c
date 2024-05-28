/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:05:07 by frlorenz          #+#    #+#             */
/*   Updated: 2024/05/16 00:33:21 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	int	check_digit(int argc, char **argv);
static	int	check_dup(int argc, char **argv);
static	int	check_limits(int argc, char **argv);
static char	**normalize(int argc, char **argv);

int	checkin(int argc, char **argv)
{
	if (check_digit(argc, argv) == 0)
		return (0);
	else if (check_dup(argc, argv) == 0)
		return (0);
	else if (check_limits(argc, argv) == 0)
		return (0);
	return (1);
}

static	int	check_digit(int argc, char **argv)
{
	int	i;

	while (--argc > 0)
	{
		i = 0;
		if (argv[argc][i] == '\0')
			return (0);
		while (argv[argc][i] != '\0')
		{
			if (!ft_isdigit(argv[argc][i]))
				if ((argv[argc][i] != '+' && argv[argc][i] != '-'))
					return (0);
			if (!ft_isdigit(argv[argc][i]))
				if (((argv[argc][i] != '+' || argv[argc][i] != '-')) && i > 0)
					return (0);
			if (!ft_isdigit(argv[argc][i]) && argv[argc][i + 1] == '\0')
				return (0);
			i++;
		}
	}
	return (1);
}

static	int	check_dup(int argc, char **argv)
{
	int	i;
	int	j;

	while (--argc > 0)
	{
		j = argc;
		while (--j > 0)
		{
			i = 0;
			while (argv[argc][i] != '\0')
			{
				if (ft_atoi(argv[argc]) == ft_atoi(argv[j]))
					return (0);
				i++;
			}
		}
		i++;
	}
	return (1);
}

static	int	check_limits(int argc, char **argv)
{
	int		len;
	char	*str;

	argv = normalize(argc, argv);
	while (--argc > 0)
	{
		len = ft_strlen(argv[argc]);
		str = ft_itoa(ft_atoi(argv[argc]));
		if (ft_strncmp(str, argv[argc], len) != 0 || len > 11)
		{
			free(str);
			return (0);
		}
		free(str);
	}
	return (1);
}

static char	**normalize(int arc, char **arv)
{
	while (--arc > 0)
	{
		if (arv[arc][0] == '+' || *arv[arc] == '0')
		{
			while ((*arv[arc] == '+' || *arv[arc] == '0') && *arv[arc] != '\0')
				arv[arc]++;
			if (arv[arc][0] == '\0')
				arv[arc]--;
		}
		else if (arv[arc][0] == '-')
		{
			while ((*arv[arc] == '-' || *arv[arc] == '0') && *arv[arc] != '\0')
				arv[arc]++;
			if (arv[arc][0] == '\0')
				arv[arc]--;
			else
			{
				arv[arc]--;
				arv[arc][0] = '-';
			}
		}
	}
	return (arv);
}
