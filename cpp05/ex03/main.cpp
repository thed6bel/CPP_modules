/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/04 10:40:18 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(){
	try
	{
			Bureaucrat bureaucrat1 = Bureaucrat("Garp", 142);
			std::cout << bureaucrat1 << std::endl;
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			// rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
			// rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");

			std::cout << *rrf << std::endl;
			bureaucrat1.signForm(*rrf);
			bureaucrat1.executeForm(*rrf);
	
			Bureaucrat bureaucrat2 = Bureaucrat("Sengoku", 1);
			std::cout << bureaucrat2 << std::endl;
			bureaucrat2.signForm(*rrf);
			bureaucrat2.executeForm(*rrf);
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
