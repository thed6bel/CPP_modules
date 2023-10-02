/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:58:33 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/27 14:11:47 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat._name), _grade(bureaucrat._grade) {
	
}

Bureaucrat::~Bureaucrat() {
	
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &bureaucrat) {
	if (this != &bureaucrat)
		_grade = bureaucrat._grade;
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	checkExceptions(grade);
	_grade = grade;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	checkExceptions(_grade - 1);
	std::cout << "incrementGrade" << std::endl;
	_grade--;
}

void Bureaucrat::decrementGrade() {
	checkExceptions(_grade + 1);
	std::cout << "decrementGrade" << std::endl;
	_grade++;
}

void Bureaucrat::checkExceptions(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}
