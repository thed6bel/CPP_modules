/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:31:35 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/06 12:59:11 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base * Base::generate(void) {
	std::srand(std::time(0));
	int i = std::rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}
//verifier si return is NULL
void Base::identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "*A Type" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "*B Type" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "*C Type" << std::endl;
	else
		std::cout << "NULL" << std::endl;
}
//utiliser try and catch 
void Base::identify(Base& p) {
	try {
		if (dynamic_cast<A*>(&p))
			std::cout << "&A Type" << std::endl;
		else if (dynamic_cast<B*>(&p))
			std::cout << "&B Type" << std::endl;
		else if (dynamic_cast<C*>(&p))
			std::cout << "&C Type" << std::endl;
	}
	catch (std::bad_cast &bc) {
		std::cerr << "Bad_cast caught: " << bc.what() << std::endl;
	}
}
