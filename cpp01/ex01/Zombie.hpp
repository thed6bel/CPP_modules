/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:41 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/14 15:00:30 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		static std::string def_name;
		Zombie(void);
		Zombie(std::string name);
		~Zombie();
		void announce(void);
		void set_name(std::string name);
};

Zombie* zombieHorde( int N, std::string name );
