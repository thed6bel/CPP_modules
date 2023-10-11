/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/03 15:04:58 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
	try
	{
			Bureaucrat bureaucrat1 = Bureaucrat("Garp", 42);
			// PresidentialPardonForm form1 = PresidentialPardonForm("Luffy");
			ShrubberyCreationForm form2 = ShrubberyCreationForm("Zoro");
			RobotomyRequestForm form3 = RobotomyRequestForm("Sanji");

			// std::cout << bureaucrat1 << std::endl;
			// std::cout << form1 << std::endl;
			// std::cout << form2 << std::endl;
			// std::cout << form3 << std::endl;

			
			// bureaucrat1.signForm(form1);
			// std::cout << form1 << std::endl;
			// bureaucrat1.signForm(form1);
			// bureaucrat1.executeForm(form1);
			// bureaucrat1.incrementGrade();
			// bureaucrat1.signForm(form1);
			// bureaucrat1.executeForm(form1);
			// bureaucrat1.incrementGrade();
			// bureaucrat1.incrementGrade();
			// bureaucrat1.incrementGrade();
			// std::cout << bureaucrat1 << std::endl;
			// bureaucrat1.signForm(form1);
			// bureaucrat1.executeForm(form1);
			// bureaucrat1.incrementGrade();
			// bureaucrat1.executeForm(form1);
			// bureaucrat1.incrementGrade();
			bureaucrat1.signForm(form2);
			// std::cout << form2 << std::endl;
			// form2.execute(bureaucrat1);
			bureaucrat1.signForm(form3);
			// std::cout << form3 << std::endl;
			// form3.execute(bureaucrat1);
			// form3.execute(bureaucrat1);
			bureaucrat1.executeForm(form3);
			bureaucrat1.executeForm(form2);

	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
