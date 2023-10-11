/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:13:20 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/04 10:37:46 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() : _name("Intern") {

}

Intern::Intern(const Intern &copy) {
	*this = copy;
}

Intern &Intern::operator = (const Intern &copy) {
	if (this != &copy)
		_name = copy._name;
	return *this;
}

Intern::~Intern() {

}

AForm *Intern::makeForm(std::string formName, std::string target) {
	std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int i;
    for (i = 0; i < 3; i++) {
        if (formName == forms[i])
            break ;
    }
    switch (i)
    {
    case 0:
        return new RobotomyRequestForm(target);    
    case 1:
        return new PresidentialPardonForm(target);
    case 2:
        return new ShrubberyCreationForm(target);
    default:
        throw Intern::InternFailException();
    }
}

const char *Intern::InternFailException::what() const throw() {
	return "Intern fail";
}
