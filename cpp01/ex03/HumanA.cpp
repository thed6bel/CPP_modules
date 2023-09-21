/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:21:34 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/15 10:53:51 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::~HumanA(){
}

HumanA::HumanA(std::string name, Weapon &weapon) :  _name(name), _weapon(weapon) {
}

void HumanA::attack(void) {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon weapon) {
	this->_weapon = weapon;
}
