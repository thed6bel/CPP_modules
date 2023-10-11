/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:58:33 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/03 15:01:19 by hucorrei         ###   ########.fr       */
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
    if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	try {
        checkExceptions(grade);
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    _grade = grade;
}

void Bureaucrat::signForm(AForm &Aform) {
	try {
        Aform.beSigned(*this);
        std::cout << this->getName() << " signed " << Aform.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << this->getName() << " couldn't sign " << Aform.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &Aform) const {
	try {
		Aform.execute(*this);
		std::cout << this->getName() << " executed " << Aform.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << this->getName() << " couldn't execute " << Aform.getName() << " because " << e.what() << std::endl;
	}
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	try {
		checkExceptions(_grade - 1);
		std::cout << "incrementGrade" << std::endl;
		_grade--;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Caught an exception: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Caught an exception: " << e.what() << std::endl;
	}
	
}

void Bureaucrat::decrementGrade() {
	try {
		checkExceptions(_grade + 1);
		std::cout << "decrementGrade" << std::endl;
		_grade++;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Caught an exception: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Caught an exception: " << e.what() << std::endl;
	}
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
