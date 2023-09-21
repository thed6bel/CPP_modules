/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:21:42 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/15 10:54:43 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#pragma once

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void attack(void);
		void setWeapon(Weapon &weapon);
};