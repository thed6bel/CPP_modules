/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:12:28 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/13 14:14:06 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){

}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarconverter){
	*this = scalarconverter;
}

ScalarConverter::~ScalarConverter(){

}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &scalarconverter){
	(void)scalarconverter;
	return (*this);
}

void ScalarConverter::convert(const std::string& str){
	int type = getType(str);
	std::cout.precision(1);
	char * endPtr;
	long intValue = std::strtol(str.c_str(), &endPtr, 10);
	if (type == 0){
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
		std::cout << "Float: nanf" << std::endl;
		std::cout << "Double: nan" << std::endl;
	} else {
		if (type == 1) {
			std::cout << "Char: '" << static_cast<char>(str[0]) << "'" << std::endl;
			std::cout << "Int: " << static_cast<int>(str[0]) << std::endl;
			std::cout << "Float: " << std::fixed << static_cast<float>(str[0]) << "f" << std::endl;
			std::cout << "Double: " << std::fixed << static_cast<double>(str[0]) << std::endl;
			return ;
		}
		if (atoi(str.c_str()) >= 32 && atoi(str.c_str()) <= 126 && type == 2) {
			std::cout << "Char: '" << static_cast<char>(atoi(str.c_str())) << "'" << std::endl;
		} else {
			std::cout << "Char: Non displayable" << std::endl;
		}
		if (intValue >= std::numeric_limits<int>::min() && intValue <= std::numeric_limits<int>::max()) {
			std::cout << "Int: " << static_cast<int>(atoi(str.c_str())) << std::endl;
		} else {
			std::cout << "Int: Non displayable, int min or int max is reached" << std::endl;
		}
		std::cout << "Float: " << std::fixed << static_cast<float>(atof(str.c_str())) << "f" << std::endl;
		std::cout << "Double: " << std::fixed << static_cast<double>(atof(str.c_str())) << std::endl;
	}
}

int ScalarConverter::getType(const std::string& str){
	int count_f = 0;
	int count_p = 0;
	int not_digit = 0;

	if (!str.length())
		return (0);
	if (str.length() == 1) {
		if (str[0] >= '0' && str[0] <= '9')
			return (2); //int
		else
			return (1); //char
	}
	for (int i = 0; str[i]; i++) {
		if (i == 0 && str[i] == '-')
            i++ ;
		if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
            not_digit++;
	}
	for (int i = 0; str[i]; i++) {
		if (str[i] == 'f')
			count_f++;
		if (str[i] == '.')
			count_p++;
	}
	if (count_p == 1 && count_f == 1)
		return (3); //float
	if (count_p == 1 && count_f == 0 && str.length() >= 3 && not_digit == 0 && str[str.length() - 1] != '.' && str[0] != '.')
		return (4); //double
	else
		if (not_digit == 0 && count_f == 0 && count_p == 0)
			return (2);
		return (0);
}
