/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/11 09:43:38 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int	main(void) {

	std::cout << "-----INT-----" << std::endl;
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    
    std::cout << "-----CHAR-----" << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    std::cout << "-----FLOAT-----" << std::endl;
    float e = 42.42f;
    float f = 19.19f;
    std::cout << "e = " << e << ", f = " << f << std::endl << "swap(e, f) ";
    ::swap(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << ::min( e, f ) << std::endl;
    std::cout << "max(e, f) = " << ::max( e, f ) << std::endl;

    std::cout << "-----DOUBLE-----" << std::endl;
    double g = 20.23;
    double h = 19.84;
    std::cout << "g = " << g << ", h = " << h << std::endl << "swap(g, h) ";
    ::swap(g, h);
    std::cout << "g = " << g << ", h = " << h << std::endl;
    std::cout << "min(g, h) = " << ::min( g, h ) << std::endl;
    std::cout << "max(g, h) = " << ::max( g, h ) << std::endl << std::endl;

    return 0;
}
