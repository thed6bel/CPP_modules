/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:29:38 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/03 15:47:16 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, 0){
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, 0){
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy){
	this->_target = copy._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &copy){
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

std::string RobotomyRequestForm::getTarget() const{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	if (this->getSigned() == 0)
		throw RobotomyRequestForm::RobotomyRequestFormFailException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw RobotomyRequestForm::RobotomyRequestFormExecException();
	else
	{
		std::cout << "Zing, ZZRRR, ZINGzing, ZZZZzzzzz" << std::endl;
		std::srand(static_cast<unsigned int>(std::time(nullptr)));

		int randomValue = std::rand() % 2;
		if (randomValue == 0)
			std::cout << this->_target << " has not been robotomized, BIG FAIL!!" << std::endl;
		else
			std::cout << this->_target << " has been robotomized successfully" << std::endl;
	}
}

const char* RobotomyRequestForm::RobotomyRequestFormFailException::what() const throw(){
	return ("RobotomyRequestFormFailException: Form is not signed");
}

const char* RobotomyRequestForm::RobotomyRequestFormExecException::what() const throw(){
	return ("RobotomyRequestFormExecException: Grade is too low");
}

std::ostream &operator << (std::ostream &out, const RobotomyRequestForm &obj){
	out << obj.getName() << " form, grade to sign " << obj.getGradeToSign() << ", grade to execute " << obj.getGradeToExecute() << ", target " << obj.getTarget() << std::endl;
	return (out);
}

