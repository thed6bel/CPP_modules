/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/06 11:21:10 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int	main(void){
	Data s;
    uintptr_t ptr = 0;
    Data *data = NULL;

    std::cout << "Before use cast:" << std::endl << std::endl;
    std::cout << "Data class 's'    : " << &s << std::endl;
    std::cout << "Data class '*data': " << data << std::endl;
    std::cout << "uintptr_t 'ptr'   : " << ptr << std::endl;

    std::cout << std::endl << "After cast:" << std::endl << std::endl;
    ptr = Serializer::serialize(&s);
    data = Serializer::deserialize(ptr);
    std::cout << "Data class 's'    : " << &s << std::endl;
    std::cout << "Data class '*data': " << data << std::endl;
 
    return 0;
}
