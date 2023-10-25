/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:13:20 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/13 14:07:36 by hucorrei         ###   ########.fr       */
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
    std::cout << "Intern creates " << formName << " Form" << std::endl;
    AForm *tmp;
    switch (i)
    {
    case 0:
        tmp = new RobotomyRequestForm(target);
        return tmp;
    case 1:
        tmp = new PresidentialPardonForm(target);
        return tmp;
    case 2:
        tmp = new ShrubberyCreationForm(target);
        return tmp;
    default:
        throw Intern::InternFailException();
        return tmp;
    }
}

const char *Intern::InternFailException::what() const throw() {
	return "Intern fail to create Form";
}
