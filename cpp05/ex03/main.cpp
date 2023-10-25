/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/13 13:58:16 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(){
	AForm* rrf[3];
	for (int i = 0; i < 3; i++)
		rrf[i] = NULL;
	try
	{
			Bureaucrat bureaucrat1 = Bureaucrat("Freeman", 142);
			Bureaucrat bureaucrat2 = Bureaucrat("Kheops", 1);
			Bureaucrat bureaucrat3 = Bureaucrat("Akh", 42);
			Bureaucrat bureaucrat4 = Bureaucrat("shurik'n", 1);
			std::cout << bureaucrat1;
			std::cout << bureaucrat2;
			std::cout << bureaucrat3;
			std::cout << bureaucrat4 << std::endl;
			Intern someRandomIntern;
			rrf[0] = someRandomIntern.makeForm("robotomy request", "Bender");
			rrf[1] = someRandomIntern.makeForm("shrubbery creation", "Bender");
			rrf[2] = someRandomIntern.makeForm("presidential pardon", "Bender");
			std::cout << "----------------------------------------" << std::endl;
			std::cout << *rrf[0] << std::endl;
			bureaucrat1.signForm(*rrf[0]);
			bureaucrat1.executeForm(*rrf[0]);
			bureaucrat2.signForm(*rrf[0]);
			bureaucrat2.executeForm(*rrf[0]);
			std::cout << "----------------------------------------" << std::endl;
			std::cout << *rrf[1] << std::endl;
			bureaucrat3.signForm(*rrf[1]);
			bureaucrat3.executeForm(*rrf[1]);
			std::cout << "----------------------------------------" << std::endl;
			std::cout << *rrf[2] << std::endl;
			bureaucrat4.signForm(*rrf[2]);
			bureaucrat4.executeForm(*rrf[2]);
			std::cout << "----------------------------------------" << std::endl;
			for (int i = 0; i < 3; i++)
				delete rrf[i];
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
		if (*rrf != NULL)
			for (int i = 0; i < 3; i++)
				delete rrf[i];
	}

	return 0;
}
