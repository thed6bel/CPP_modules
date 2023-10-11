/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:30:01 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/03 10:07:51 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm &operator = (const PresidentialPardonForm &obj);
		~PresidentialPardonForm();
		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
		class PresidentialPardonFormFailException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class PresidentialPardonFormExecException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator << (std::ostream &out, const PresidentialPardonForm &obj);