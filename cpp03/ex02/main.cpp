/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/25 13:11:01 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void){
	ScavTrap	a("Luffy");
	ScavTrap	b("Crocodile");
	FragTrap	c("Zoro");
	a.guardGate();
	a.attack("Crocodile");
	b.takeDamage(20);
	c.attack("Crocodile");
	b.takeDamage(30);
	c.highFivesGuys();
}
