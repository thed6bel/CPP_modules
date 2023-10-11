/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:17:52 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/03 14:46:37 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat;

class  AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		AForm();
		AForm(const AForm &form);
		virtual ~AForm() = 0;
		AForm(const std::string name, int gradeToSign, int gradeToExecute, bool _signed);
		AForm &operator = (const AForm &form);
		std::string getName() const;
		void checkExceptions(int exec) const;
		void checkSignExceptions(int sign);
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);//virtual ????
		virtual void execute(Bureaucrat const &executor) const = 0;
		void checkGradeToSign(int gradeToSign);
		void checkGradeToExecute(int gradeToExecute) const;
		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class FormSignedException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator << (std::ostream &out, const AForm &form);
