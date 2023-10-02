/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:30:17 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/22 11:31:38 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &FragTrap);
		~FragTrap();
		FragTrap &operator = (const FragTrap &FragTrap);
		FragTrap(std::string name, int hitpoints, int energyPoints, int attackDamage);
		void highFivesGuys();
		void attack(const std::string& target);
};