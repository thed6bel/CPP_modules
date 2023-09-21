/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/14 15:21:56 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void){
	std::string brain = "HI THIS IS BRAIN";

	std::string *stringPTR = &brain;

	std::string &stringREF = brain;

	std::cout << "Memory adress of string variable	: " << &brain << std::endl;
	std::cout << "Memory adress of stringPTR		: " << &stringPTR << std::endl;
	std::cout << "Memory adress of stringREF		: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of String variable	: " << brain << std::endl;
	std::cout << "Value of StringPTR		: " << *stringPTR << std::endl;
	std::cout << "Value of StringREF		: " << stringREF << std::endl;
}
