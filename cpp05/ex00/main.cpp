/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/13 09:31:49 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
	Bureaucrat *bureaucrat = new Bureaucrat("Jean_Louis_David", 1);
	try{
		std::cout << *bureaucrat;
		bureaucrat->incrementGrade();
		std::cout << *bureaucrat;
		delete bureaucrat;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
		delete bureaucrat;
	}
	std::cout << "----------------------------------" << std::endl;
	Bureaucrat *bureaucrat2 = new Bureaucrat("N125477412365817", 150);
	try
	{
		std::cout << *bureaucrat2;
		bureaucrat2->decrementGrade();
		std::cout << *bureaucrat2;
		delete bureaucrat2;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		delete bureaucrat2;
	}
	std::cout << "----------------------------------" << std::endl;
	Bureaucrat *bureaucrat3 = new Bureaucrat("R2D2.C4.1984.S19", 150);
	try
	{
		std::cout << *bureaucrat3;
		bureaucrat3->incrementGrade();
		std::cout << *bureaucrat3;
		bureaucrat3->incrementGrade();
		std::cout << *bureaucrat3;
		bureaucrat3->decrementGrade();
		std::cout << *bureaucrat3;
		delete bureaucrat3;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		delete bureaucrat3;
	}
	std::cout << "----------------------------------" << std::endl;
	try
	{
		Bureaucrat test = Bureaucrat("testerror", 151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}	
	std::cout << "----------------------------------" << std::endl;
	try
	{
		Bureaucrat test2 = Bureaucrat("testerror", 0);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}	

	return 0;
}
