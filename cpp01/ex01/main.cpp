/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/14 15:18:33 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
	Zombie *zombies = zombieHorde(5, "Zombie_of_Moria");
	zombies[3].announce();
	delete[] zombies;
	std::cout << "All Zombies of first test were destroyed" << std::endl;
	Zombie *zombies2 = zombieHorde(2, "Zombie_of_Thriller_Bark");
	zombies2[0].announce();
	delete[] zombies2;
	return (0);
}
