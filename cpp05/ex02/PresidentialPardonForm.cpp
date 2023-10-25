/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:29:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/13 10:24:23 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, 0){
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5, 0){
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy){
	this->_target = copy._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &copy){
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

std::string PresidentialPardonForm::getTarget() const{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	if (this->getSigned() == 0)
		throw PresidentialPardonForm::PresidentialPardonFormFailException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw PresidentialPardonForm::PresidentialPardonFormExecException();
	else
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

const char *PresidentialPardonForm::PresidentialPardonFormFailException::what() const throw(){
	return ("PresidentialPardonFormFailException: Form is not signed.");
}

const char *PresidentialPardonForm::PresidentialPardonFormExecException::what() const throw(){
	return ("PresidentialPardonFormExecException: Grade is too low.");
}

std::ostream &operator << (std::ostream &out, const PresidentialPardonForm &obj){
	out << obj.getName() << " form: grade to sign " << obj.getGradeToSign() << ", grade to execute " << obj.getGradeToExecute() << ", target " << obj.getTarget() << "." << std::endl;
	return (out);
}
