/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/27 14:14:15 by hucorrei         ###   ########.fr       */
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
	Bureaucrat *bureaucrat3 = new Bureaucrat("N587963489198417", 150);
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
	
	
	return 0;
}
