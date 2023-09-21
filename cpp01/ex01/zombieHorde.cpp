/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:51:21 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/15 09:54:16 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
	if (N <= 0)
		return (NULL);
	Zombie *horde;
	horde = new Zombie[N];
	for (int i = 0; i < N; i++){
		horde[i].set_name(name);
	}
	return (horde);
}
