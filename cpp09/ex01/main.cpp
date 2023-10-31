/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/30 11:20:37 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv){
    if (argc != 2) {
		std::cout << "Error" << std::endl;
        return (1);
    }
	ctrlExpression(argv[1]);
    int result = calcRPN(argv[1]);
    
    std::cout << result << std::endl;
    
    return 0;
}
