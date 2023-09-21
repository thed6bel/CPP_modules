/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/15 09:52:31 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
	Zombie Zombie_One;
	Zombie_One.announce();

	randomChump("Zombie_Two");

	Zombie *Zombie_three = newZombie("Zombie_Three");
	Zombie_three->announce();
	delete Zombie_three;
}
