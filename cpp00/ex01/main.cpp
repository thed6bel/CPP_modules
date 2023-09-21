/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:04:36 by hucorrei          #+#    #+#             */
/*   Updated: 2023/08/24 11:59:46 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <csignal>
#include <cstdlib>

void handleCtrlC(int signal) {
	std::cout << std::endl << "\033[1;31mReceived Ctrl+C signal (" << signal << "). Exiting...\033[0m" << std::endl;
	exit(signal);
}

void handleCtrlBackslash(int signal) {
	std::cout << std::endl << "\033[1;31mReceived Ctrl+\\ signal (" << signal << "). Exiting...\033[0m" << std::endl;
	exit(signal);
}

int main()
{
	PhoneBook phonebook;
	std::string command;

	signal(SIGINT, handleCtrlC);
    signal(SIGQUIT, handleCtrlBackslash);

	while (1)
	{
		std::cout << "\033[32mEnter command, You can use ADD, SEARCH or EXIT only: \033[0m";
		std::getline(std::cin, command);
		if (std::cin.eof()){
			std::cout << std::endl << "\033[1;31mReceived Ctrl+D signal. Exiting...\033[0m" << std::endl;
			exit(0);
		}
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else
			std::cout << "\033[1;31mInvalid command\033[0m" << std::endl;
	}
	return (0);
}
