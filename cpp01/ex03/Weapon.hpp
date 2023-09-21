/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:21:48 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/15 11:00:50 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#pragma once

class Weapon
{
	private:
		std::string type;
	public:
		~Weapon();
		Weapon(std::string type);
		const std::string &getType();
		void setType(std::string New_Type);
};
