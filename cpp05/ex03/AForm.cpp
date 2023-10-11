/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:18:00 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/03 15:08:18 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	
}

AForm::AForm(const AForm &form) : _name(form.getName()), _signed(form.getSigned()), _gradeToSign(form.getGradeToSign()), _gradeToExecute(form.getGradeToExecute()) {
	
}

AForm::~AForm() {
	
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute, bool _signed) : _name(name), _signed(_signed), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
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

AForm &AForm::operator = (const AForm &form) {
	(void)form;
	return *this;
}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getSigned() const {
	return this->_signed;
}

int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw AForm::GradeTooLowException();
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

void AForm::checkGradeToSign(int gradeToSign) {
	try {
		if (gradeToSign < 1) {
			throw AForm::GradeTooHighException();
		}
		else if (gradeToSign > 150) {
			throw AForm::GradeTooLowException();
		}
	} catch (const AForm::GradeTooLowException &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
	}
}

void AForm::checkGradeToExecute(int gradeToExecute) const {
	if (gradeToExecute < 1) {
		throw AForm::GradeTooHighException();
	}
	else if (gradeToExecute > 150) {
		throw AForm::GradeTooLowException();
	}
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Form too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Form too low";
}

const char *AForm::FormSignedException::what() const throw() {
	return "Form is signed";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

std::ostream &operator << (std::ostream &out, const AForm &Aform) {
	out << "Form name: " << Aform.getName() << std::endl;
	out << "Form signed: " << Aform.getSigned() << std::endl;
	out << "Form grade to sign: " << Aform.getGradeToSign() << std::endl;
	out << "Form grade to execute: " << Aform.getGradeToExecute() << std::endl;
	return out;
}

void AForm::checkExceptions(int exec) const {
	try {
		if (exec < 1) {
			throw AForm::GradeTooHighException();
		}
		else if (exec > 150) {
			throw AForm::GradeTooLowException();
		}
	} catch (const AForm::GradeTooLowException &e) {
	std::cerr << "Caught an exception: " << e.what() << std::endl;
	}
}

void AForm::checkSignExceptions(int sign) {
	try {
		if (sign < 1) {
			throw AForm::GradeTooHighException();
		}
		else if (sign > 150) {
			throw AForm::GradeTooLowException();
		}
		else if (this->_signed == true) {
			throw AForm::FormSignedException();
		}
	} catch (const AForm::GradeTooLowException &e) {
	std::cerr << "Caught an exception: " << e.what() << std::endl;
	}
}
