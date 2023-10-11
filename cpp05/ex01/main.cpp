/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/02 14:47:13 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	try
	{
			Bureaucrat bureaucrat1 = Bureaucrat("bureaucrat1", 6);
			Form form1 = Form("form1", 5, 1, false);

			std::cout << bureaucrat1 << std::endl;
			std::cout << form1 << std::endl;

			
			bureaucrat1.signForm(form1);
			std::cout << form1 << std::endl;
			bureaucrat1.signForm(form1);
			bureaucrat1.executeForm(form1);
			bureaucrat1.incrementGrade();
			bureaucrat1.signForm(form1);
			bureaucrat1.executeForm(form1);
			bureaucrat1.incrementGrade();
			bureaucrat1.incrementGrade();
			bureaucrat1.incrementGrade();
			std::cout << bureaucrat1 << std::endl;
			bureaucrat1.signForm(form1);
			bureaucrat1.executeForm(form1);
			bureaucrat1.incrementGrade();
			bureaucrat1.executeForm(form1);
			bureaucrat1.incrementGrade();

	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
