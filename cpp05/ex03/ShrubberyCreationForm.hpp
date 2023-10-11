/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:29:34 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/03 13:55:55 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator = (const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();
		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
		class ShrubberyCreationFormFailException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class ShrubberyCreationFormExecException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator << (std::ostream &out, const ShrubberyCreationForm &obj);