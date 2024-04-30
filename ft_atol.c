/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:54:54 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/30 01:54:54 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(char *nptr)
{
	int	minus;
	int	i;
	int	result;

	minus = 0;
	result = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		minus = (nptr[i] == 45);
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	if (minus != 0)
		result *= -1;
	return (result);
}
