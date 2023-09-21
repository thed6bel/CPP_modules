/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:41 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/08 12:05:54 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie();
		void announce(void);
};

Zombie*	newZombie( std::string name );
void 	randomChump( std::string name );
