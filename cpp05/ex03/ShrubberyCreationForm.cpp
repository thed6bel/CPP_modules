/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:29:29 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/03 13:56:01 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137, 0) {
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137, 0) {
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {
	this->_target = copy._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &copy) {
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

std::string ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (this->getSigned() == 0)
		throw ShrubberyCreationForm::ShrubberyCreationFormFailException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw ShrubberyCreationForm::ShrubberyCreationFormExecException();
	else
	{
		std::ofstream file;
		std::string filename = this->_target + "_shrubbery";
		file.open(filename.c_str());
		if (file.is_open()) {
			file << "     ^" << std::endl;
			file << "    ^^^" << std::endl;
			file << "   ^^^^^" << std::endl;
			file << "  ^^^^^^^" << std::endl;
			file << " ^^^^^^^^^" << std::endl;
			file << "^^^^^^^^^^^" << std::endl;
			file << "     |" << std::endl;
			file.close();
		} else {
			std::cout << "Error opening file" << std::endl;
		}
	}
	std::cout << "ShrubberyCreationForm executed and file is created" << std::endl;
}

const char *ShrubberyCreationForm::ShrubberyCreationFormFailException::what() const throw() {
	return ("ShrubberyCreationFormFailException: Form is not signed.");
}

const char *ShrubberyCreationForm::ShrubberyCreationFormExecException::what() const throw() {
	return ("ShrubberyCreationFormExecException: Grade is too low.");
}

std::ostream &operator << (std::ostream &out, const ShrubberyCreationForm &obj) {
	out << obj.getName() << " form with grade to sign " << obj.getGradeToSign() << " and grade to execute " << obj.getGradeToExecute() << " and target " << obj.getTarget() << " ,is signed " << std::boolalpha << obj.getSigned() << std::endl;
	return (out);
}
