/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:21:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/15 11:00:55 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::~Weapon(void) {
}

Weapon::Weapon(std::string Type) {
	this->type = Type;
}

void Weapon::setType(std::string New_Type) {
	this->type = New_Type;
}

const std::string &Weapon::getType(void){
	return (this->type);
}
