/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:29:41 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/03 13:56:05 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator = (const RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
		class RobotomyRequestFormFailException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class RobotomyRequestFormExecException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator << (std::ostream &out, const RobotomyRequestForm &obj);