/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/15 11:42:02 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv){
	Harl harl;
	std::string tmp[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	if (argc == 2){
		for (int i = 0; i < 4; i++){
		if (tmp[i] == argv[1]){
			harl.complain(argv[1]);
			return (0);
			}
		}
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	if (argc == 1){
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
	}
	else{
		std::cout << "\033[1;31mError:\033[0m wrong number of arguments or bad level request" << std::endl;
		std::cout << "Usage: ./harl <LEVEL> or just ./harl" << std::endl;
	}
	return (1);
}
