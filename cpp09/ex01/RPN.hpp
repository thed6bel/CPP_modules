/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:04:38 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/30 11:39:14 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <stack>

// class RPN {
//     private:
//         std::stack<int> _numbers;
//         RPN();
//     public:
//         RPN(std::string expression);
//         RPN(const RPN& copy);
//         ~RPN();
//         RPN& operator=(const RPN& op);
//         void ctrlExpression(std::string expression);
// };

int calcRPN(const std::string& expression);
void ctrlExpression(std::string expression);