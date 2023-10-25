/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/13 11:15:23 by hucorrei         ###   ########.fr       */
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
			Bureaucrat bureaucrat1 = Bureaucrat("Smoker", 26);
			Bureaucrat bureaucrat2 = Bureaucrat("Garp", 5);
			Bureaucrat bureaucrat3 = Bureaucrat("Sengoku", 138);
			PresidentialPardonForm form1 = PresidentialPardonForm("Luffy");
			ShrubberyCreationForm form2 = ShrubberyCreationForm("Zoro");
			RobotomyRequestForm form3 = RobotomyRequestForm("Franky");

			std::cout << bureaucrat1;
			std::cout << bureaucrat2;
			std::cout << form1;
			std::cout << form2;
			std::cout << form3;

			std::cout << "---------------------------" << std::endl;
			bureaucrat1.signForm(form1);
			bureaucrat1.executeForm(form1);
			bureaucrat1.incrementGrade();
			bureaucrat1.signForm(form1);
			bureaucrat2.executeForm(form1);

			std::cout << "---------------------------" << std::endl;
			bureaucrat3.signForm(form2);
			bureaucrat3.incrementGrade();
			form2.execute(bureaucrat3);

			std::cout << "---------------------------" << std::endl;
			bureaucrat1.signForm(form3);
			bureaucrat1.executeForm(form3);

	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
