/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/17 12:43:40 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void){
    
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    try {
        std::cout << easyfind(v, 2) << std::endl;
        std::cout << easyfind(v, 4) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Not found" << std::endl;
    }

    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    try {
        std::cout << easyfind(l, 2) << std::endl;
        std::cout << easyfind(l, 4) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}
