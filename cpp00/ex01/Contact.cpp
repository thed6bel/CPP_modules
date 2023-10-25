/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:52:38 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/23 10:57:31 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	this->info[0] = "Index       : ";
	this->info[1] = "First name  : ";
	this->info[2] = "Last name   : ";
	this->info[3] = "Nickname    : ";
	this->info[4] = "Phone num.  : ";
	this->info[5] = "Darkest sec.: ";
}

Contact::~Contact() {}

void ctrl_d() {
	std::cout << std::endl << "\033[1;31mReceived Ctrl+D signal. Exiting...\033[0m" << std::endl;
			exit(0);
}

void Contact::add_contact(int buff) {
	std::string input;

	if (this->_index.empty()) {
		this->_index.insert(this->_index.end(), (char)(buff + 48));
	} else {
		this->_index.clear();
		this->_index.insert(this->_index.end(), (char)(buff + 48));
	}
	do {
		std::cout << "Please enter the first name: ";
		std::getline(std::cin, input);
		if (std::cin.eof()){
			ctrl_d();
		}
		if (input.empty())
			std::cout << "\033[1;31mNo empty line, \033[0m";
	} while (input.empty());
	this->_first_name = input;
	do {
		std::cout << "Please enter the last name: ";
		std::getline(std::cin, input);
		if (std::cin.eof()){
			ctrl_d();
		}
		if (input.empty())
			std::cout << "\033[1;31mNo empty line, \033[0m";
	} while (input.empty());
	this->_last_name = input;
	do {
		std::cout << "Please enter the nickname: ";
		std::getline(std::cin, input);
		if (std::cin.eof()){
			ctrl_d();
		}
		if (input.empty())
			std::cout << "\033[1;31mNo empty line, \033[0m";
	} while (input.empty());
	this->_nickname = input;
	bool validPhoneNumber = false;
	do {
		std::cout << "Please enter the phone number: ";
		std::getline(std::cin, input);
		if (std::cin.eof()){
			ctrl_d();
		}
		if (input.empty())
			std::cout << "\033[1;31mNo empty line, \033[0m";
		validPhoneNumber = true;
		if (!input.empty()) {
			if (input[0] == '+') {
				for (size_t i = 1; i < input.length(); ++i) {
					if (!std::isdigit(input[i])) {
						validPhoneNumber = false;
						std::cout << "\033[1;31mInvalid phone number. Please enter a number with digits only or '+' for international.\033[0m" << std::endl;
						break;
					}
				}
			} else {
				for (size_t i = 0; i < input.length(); ++i) {
					if (!std::isdigit(input[i])) {
						validPhoneNumber = false;
						std::cout << "\033[1;31mInvalid phone number. Please enter a number with digits only or '+' for international.\033[0m" << std::endl;
						break;
					}
				}
			}
		} else
			validPhoneNumber = false;
	} while (!validPhoneNumber);
	this->_phone_number = input;
	do {
		std::cout << "Please enter his darkest secret: ";
		std::getline(std::cin, input);
		if (std::cin.eof()){
			ctrl_d();
		}
		if (input.empty())
			std::cout << "\033[1;31mNo empty line, \033[0m";
	} while (input.empty());
	this->_darkest_secret = input;
	this->_obj[0] = this->_index;
	this->_obj[1] = this->_first_name;
	this->_obj[2] = this->_last_name;
	this->_obj[3] = this->_nickname;
	this->_obj[4] = this->_phone_number;
	this->_obj[5] = this->_darkest_secret;
}

void	Contact::search_contact(int p, int char_disp){
	int nb = 0;
	if (char_disp)
		std::cout << "|";
	for (int i = 0; i < p; i++) {
		if (!char_disp) {
			std::cout << this->info[i];
			std::cout << (this->_obj[i]) << std::endl;
		}
		else if ((this->_obj[i]).length() > 10)
			std::cout << (this->_obj[i]).substr(0, 9) << ".|";
		else {
			nb = 10 - (this->_obj[i]).length();
			while (nb--)
				std::cout << " ";
			std::cout << (this->_obj[i]) << "|";
//utiliser setw(10) a la place d code dans le esle pour aligner et donc utiliser les iomanip
		}
	}
	if (char_disp)
		std::cout << std::endl;
}
