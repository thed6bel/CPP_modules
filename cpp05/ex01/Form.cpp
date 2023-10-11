/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:18:00 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/02 14:35:33 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	
}

Form::Form(const Form &form) : _name(form.getName()), _signed(form.getSigned()), _gradeToSign(form.getGradeToSign()), _gradeToExecute(form.getGradeToExecute()) {
	
}

Form::~Form() {
	
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute, bool _signed) : _name(name), _signed(_signed), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
	try {
		checkExceptions(gradeToExecute);
		checkExceptions(gradeToSign);
	}
	catch (const std::exception& e) {
		std::cout << "test exec form" << std::endl;
		throw;
	}
}

Form &Form::operator = (const Form &form) {
	(void)form;
	return *this;
}

std::string Form::getName() const {
	return this->_name;
}

bool Form::getSigned() const {
	return this->_signed;
}

int Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw Form::GradeTooLowException();
	}
    try {
        checkSignExceptions(bureaucrat.getGrade());
    }
    catch (const std::exception& e) {
        throw;
    }
	try {
		checkGradeToSign(bureaucrat.getGrade());
	}
	catch (const std::exception& e) {
		throw;
	}
	this->_signed = true;
}

void Form::beExecuted(Bureaucrat &bureaucrat) {
	if (this->_signed == false) {
		throw Form::FormNotSignedException();
	}
	if (bureaucrat.getGrade() > this->_gradeToExecute) {
		throw Form::GradeTooLowException();
	}
	try {
		checkExceptions(bureaucrat.getGrade());
	}
	catch (const std::exception& e) {
		throw;
	}
	try {
		checkGradeToExecute(bureaucrat.getGrade());
	}
	catch (const std::exception& e) {
		throw;
	}
}

void Form::checkGradeToSign(int gradeToSign) {
	try {
		if (gradeToSign < 1) {
			throw Form::GradeTooHighException();
		}
		else if (gradeToSign > 150) {
			throw Form::GradeTooLowException();
		}
	} catch (const Form::GradeTooLowException &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
	}
}

void Form::checkGradeToExecute(int gradeToExecute) {
	if (gradeToExecute < 1) {
		throw Form::GradeTooHighException();
	}
	else if (gradeToExecute > 150) {
		throw Form::GradeTooLowException();
	}
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Form too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form too low";
}

const char *Form::FormSignedException::what() const throw() {
	return "Form is signed";
}

const char *Form::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

std::ostream &operator << (std::ostream &out, const Form &form) {
	out << "Form name: " << form.getName() << std::endl;
	out << "Form signed: " << form.getSigned() << std::endl;
	out << "Form grade to sign: " << form.getGradeToSign() << std::endl;
	out << "Form grade to execute: " << form.getGradeToExecute() << std::endl;
	return out;
}

void Form::checkExceptions(int exec) {
	try {
		if (exec < 1) {
			throw Form::GradeTooHighException();
		}
		else if (exec > 150) {
			throw Form::GradeTooLowException();
		}
	} catch (const Form::GradeTooLowException &e) {
	std::cerr << "Caught an exception: " << e.what() << std::endl;
	}
}

void Form::checkSignExceptions(int sign) {
	try {
		if (sign < 1) {
			throw Form::GradeTooHighException();
		}
		else if (sign > 150) {
			throw Form::GradeTooLowException();
		}
		else if (this->_signed == true) {
			throw Form::FormSignedException();
		}
	} catch (const Form::GradeTooLowException &e) {
	std::cerr << "Caught an exception: " << e.what() << std::endl;
	}
}

