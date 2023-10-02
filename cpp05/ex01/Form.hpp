/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:17:52 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/02 13:38:19 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat;

class  Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
		void checkExceptions(int exec);
		void checkSignExceptions(int sign);
	public:
		Form();
		Form(const Form &form);
		~Form();
		Form(const std::string name, int gradeToSign, int gradeToExecute, bool _signed);
		Form &operator = (const Form &form);
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
		void beExecuted(Bureaucrat &bureaucrat);
		void checkGradeToSign(int gradeToSign);
		void checkGradeToExecute(int gradeToExecute);
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

std::ostream &operator << (std::ostream &out, const Form &form);
