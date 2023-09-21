/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:25:44 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/21 14:11:16 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap"){
	std::cout << "ScavTrap default constructor called" << std::endl;
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

ScavTrap::ScavTrap(std::string name, int Hitpoints, int EnergyPoints, int AttackDamage){
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_Name = name;
	this->_Hitpoints = Hitpoints;
	this->_EnergyPoints = EnergyPoints;
	this->_AttackDamage = AttackDamage;
}