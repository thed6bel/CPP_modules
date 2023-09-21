/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:37 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/11 14:08:25 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void): _name("Zombie_One"){
	std::cout << this->_name << " : was created" << std::endl;
}

Zombie::Zombie(std::string name): _name(name){
	std::cout << this->_name << " : was created" << std::endl;
}

Zombie::~Zombie(){
	std::cout << this->_name << " : was destroyed" << std::endl;
}

void Zombie::announce(void){
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
