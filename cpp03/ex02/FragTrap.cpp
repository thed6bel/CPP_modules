/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:30:23 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/22 11:41:12 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_Name = "Default";
	this->_Hitpoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << "FragTrap constructor called" << std::endl;
	this->_Name = name;
	this->_Hitpoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &FragTrap){
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = FragTrap;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &FragTrap){
	std::cout << "FragTrap assignation operator called" << std::endl;
	this->_Name = FragTrap._Name;
	this->_Hitpoints = FragTrap._Hitpoints;
	this->_EnergyPoints = FragTrap._EnergyPoints;
	this->_AttackDamage = FragTrap._AttackDamage;
	return (*this);
}

FragTrap::FragTrap(std::string name, int Hitpoints, int EnergyPoints, int AttackDamage){
	std::cout << "FragTrap constructor called" << std::endl;
	this->_Name = name;
	this->_Hitpoints = Hitpoints;
	this->_EnergyPoints = EnergyPoints;
	this->_AttackDamage = AttackDamage;
}

void FragTrap::highFivesGuys(){
	std::cout << "FragTrap " << this->_Name << " is asking for high fives" << std::endl;
}

void FragTrap::attack(const std::string& target){
	if (this->_EnergyPoints == 0 || this->_Hitpoints == 0){
		return ;
	}
	std::cout << "FragTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
	this->_EnergyPoints -= 1;
	std::cout << "FragTrap " << this->_Name << " has " << this->_EnergyPoints << " energy points left!" << std::endl;
}