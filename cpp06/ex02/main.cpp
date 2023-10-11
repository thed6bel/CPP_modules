/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/06 12:00:56 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>

int	main(void){
    clock_t start_time = clock();
    Base* ptr = Base::generate();
    
    Base&   ref1 = *ptr;
    ptr->identify(ptr);
    ref1.identify(ref1);
    delete ptr;
    std::cout << std::endl << "waiting 2 secondes" << std::endl;
    while ((clock() - start_time) / CLOCKS_PER_SEC < 2) {}
    std::cout << std::endl;
    ptr = Base::generate();
    Base&   ref2 = *ptr;
    ptr->identify(ptr);
    ref2.identify(ref2);
    delete ptr;
    start_time = clock();
    std::cout << std::endl << "waiting 2 secondes" << std::endl;
    while ((clock() - start_time) / CLOCKS_PER_SEC < 2) {}
    std::cout << std::endl;
    ptr = Base::generate();
    Base&   ref3 = *ptr;
    ptr->identify(ptr);
    ref3.identify(ref3);
    delete ptr;
}
