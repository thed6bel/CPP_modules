/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:58:37 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/02 13:34:10 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
		void checkExceptions(int grade);
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat();
		Bureaucrat &operator = (const Bureaucrat &bureaucrat);
		Bureaucrat(std::string name, int grade);
		std::string getName() const;
		int getGrade() const;
		void signForm(Form &form);
		void executeForm(Form &form);
		void incrementGrade();
		void decrementGrade();
		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat);

#endif