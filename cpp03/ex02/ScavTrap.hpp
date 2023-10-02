/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:24:38 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/22 10:51:50 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &ScavTrap);
		~ScavTrap();
		ScavTrap &operator = (const ScavTrap &ScavTrap);
		ScavTrap(std::string name, int hitpoints, int energyPoints, int attackDamage);
		void guardGate();
		void attack(const std::string& target);
};
