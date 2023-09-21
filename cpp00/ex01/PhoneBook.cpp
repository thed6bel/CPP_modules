/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:52:51 by hucorrei          #+#    #+#             */
/*   Updated: 2023/08/24 11:58:20 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void) {
	this->_buff = 0;
}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::add_contact(void){
	int index = this->_buff % 8;
	this->_contacts[index].add_contact(index + 1);
	this->_buff++;
}

void PhoneBook::search_contact(void) {
	std::string input;
	int i = -1;
	if (this->_buff == 0) {
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}
	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (++i < this->_buff && i < 8)
		this->_contacts[i].search_contact(4, 10);
	int index;
	std::cout << " ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	bool isValidIndex = false;
	while (!isValidIndex) {
		std::string input;
		std::cout << "Please choose the index to display: ";
		std::getline(std::cin, input);
		if (std::cin.eof()){
			std::cout << std::endl << "\033[1;31mReceived Ctrl+D signal. Exiting...\033[0m" << std::endl;
			exit(0);
		}
		index = atoi(input.c_str());
		if (index > 0 && index <= this->_buff && index <= 8) {
			this->_contacts[index - 1].search_contact(6, 0);
			isValidIndex = true;
		} else {
			std::cout << "\033[1;31mInvalid or empty index. Please enter a valid index.\033[0m" << std::endl;
		}
	}
}
