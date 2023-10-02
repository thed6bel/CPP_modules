/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:25:44 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/22 13:14:13 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_Name = "Default Name";
	this->_Hitpoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_Name = name;
	this->_Hitpoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &ScavTrap){
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = ScavTrap;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &ScavTrap){
	std::cout << "ScavTrap assignation operator called" << std::endl;
	this->_Name = ScavTrap._Name;
	this->_Hitpoints = ScavTrap._Hitpoints;
	this->_EnergyPoints = ScavTrap._EnergyPoints;
	this->_AttackDamage = ScavTrap._AttackDamage;
	return (*this);
}

ScavTrap::ScavTrap(std::string name, int Hitpoints, int EnergyPoints, int AttackDamage) : ClapTrap(name){
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_Name = name;
	this->_Hitpoints = Hitpoints;
	this->_EnergyPoints = EnergyPoints;
	this->_AttackDamage = AttackDamage;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->_Name << " has entered in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (this->_EnergyPoints == 0 || this->_Hitpoints == 0){
		return ;
	}
	std::cout << "ScavTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
	this->_EnergyPoints -= 1;
	std::cout << "ScavTrap " << this->_Name << " has " << this->_EnergyPoints << " energy points left!" << std::endl;
}
