/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:12:26 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/31 14:51:19 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	ft_upper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			std::cout << (char)(str[i] - 32);
		else
			std::cout << str[i];
		i++;
	}
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (argv[i])
		{
			ft_upper(argv[i]);
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
