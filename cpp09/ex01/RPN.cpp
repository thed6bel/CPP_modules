/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:04:42 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/30 11:38:48 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int calcRPN(const std::string& expression) {
    std::stack<int> numbers;

    std::stringstream ss(expression);
    std::string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            int number = std::atoi(token.c_str());
            numbers.push(number);
        } else {
            int operand2 = numbers.top();
            numbers.pop();
            int operand1 = numbers.top();
            numbers.pop();
            
            if (token == "+") {
                numbers.push(operand1 + operand2);
            } else if (token == "-") {
                numbers.push(operand1 - operand2);
            } else if (token == "*") {
                numbers.push(operand1 * operand2);
            } else if (token == "/") {
                numbers.push(operand1 / operand2);
            }
        }
    }
    return numbers.top();
}

void ctrlExpression(std::string expression) {
	if (expression == "") {
		std::cout << "Error" << std::endl;
		exit(1);
	}
	for (int i = 0; expression[i]; i++) {
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == ' ') {
			if (expression[i] == ' ') {
				if (expression[i + 1] == ' ' || expression[i + 1] == '\0') {
					std::cout << "Error" << std::endl;
					exit(1);
				}
			}
		}
		else if (isdigit(expression[i])) {
			continue;
		}
		else {
			std::cout << "Error" << std::endl;
			exit(1);
		}
	}
}

// RPN::RPN() {}

// RPN::RPN(std::string expression) {
// 	ctrlExpression(expression);
// 	std::stringstream ss(expression);
// 	std::string token;
// 	while (ss >> token) {
// 		if (isdigit(token[0])) {
// 			int number = std::atoi(token.c_str());
// 			_numbers.push(number);
// 		} else {
// 			int operand2 = _numbers.top();
// 			_numbers.pop();
// 			int operand1 = _numbers.top();
// 			_numbers.pop();
			
// 			if (token == "+") {
// 				_numbers.push(operand1 + operand2);
// 			} else if (token == "-") {
// 				_numbers.push(operand1 - operand2);
// 			} else if (token == "*") {
// 				_numbers.push(operand1 * operand2);
// 			} else if (token == "/") {
// 				_numbers.push(operand1 / operand2);
// 			}
// 		}
// 	}
// }

// RPN::RPN(const RPN& copy) {
// 	*this = copy;
// }

// RPN::~RPN() {}

// RPN& RPN::operator=(const RPN& op) {
// 	if (this == &op)
// 		return *this;
// 	_numbers = op._numbers;
// 	return *this;
// }