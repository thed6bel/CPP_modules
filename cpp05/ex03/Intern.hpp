/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:13:23 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/03 15:16:41 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;

class Intern
{
	private:
		std::string _name;
	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator = (const Intern &copy);
		~Intern();
		AForm *makeForm(std::string formName, std::string target);
		class InternFailException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};