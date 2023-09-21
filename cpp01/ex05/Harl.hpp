/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:35:28 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/13 14:40:17 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#pragma once

class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();
		void (Harl:: *f[4])();

	public:
		void complain(std::string level);
		Harl();
		~Harl();
};
