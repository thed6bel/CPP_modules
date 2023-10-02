/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:44:05 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/26 10:33:11 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_Name = "Default Name";
	this->_Hitpoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
}

ClapTrap::ClapTrap(std::string name){
	std::cout << "ClapTrap constructor called" << std::endl;
	this->_Name = name;
	this->_Hitpoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &ClapTrap){
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = ClapTrap;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &ClapTrap){
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->_Name = ClapTrap._Name;
	this->_Hitpoints = ClapTrap._Hitpoints;
	this->_EnergyPoints = ClapTrap._EnergyPoints;
	this->_AttackDamage = ClapTrap._AttackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target){
	if (this->_EnergyPoints == 0 || this->_Hitpoints == 0){
		return ;
	}
	std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
	this->_EnergyPoints -= 1;
	std::cout << "ClapTrap " << this->_Name << " has " << this->_EnergyPoints << " energy points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_Hitpoints == 0){
		return ;
	}
	std::cout << "ClapTrap " << this->_Name << " takes " << amount << " points of damage!" << std::endl;
	this->_Hitpoints -= amount;
	if (this->_Hitpoints <= 0){
		this->_Hitpoints = 0;
		std::cout << "ClapTrap " << this->_Name << " has no more hit points left : he died" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_Name << " has " << this->_Hitpoints << " hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_EnergyPoints == 0 || this->_Hitpoints == 0){
		return ;
	}
	this->_EnergyPoints -= 1;
	std::cout << "ClapTrap " << this->_Name << " is repaired by " << amount << " points!" << std::endl;
	if (this->_Hitpoints + amount > 100)
		this->_Hitpoints = 100;
	else
		this->_Hitpoints += amount;
	std::cout << "ClapTrap " << this->_Name << " has " << this->_Hitpoints << " hit points left!" << std::endl;
	std::cout << "ClapTrap " << this->_Name << " has " << this->_EnergyPoints << " energy points left!" << std::endl;
}

int ClapTrap::getEnergyPoints(){
	return (this->_EnergyPoints);
}

int ClapTrap::getHitpoints(){
	return (this->_Hitpoints);
}
