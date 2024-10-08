/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/17 11:37:58 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <sstream>

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

int	main(void){
    
    Array<int> a(5);
    Array<int> b(5);
    Array<std::string> c(5);
    Array<int> d(5);
    Array<int> f;// empty array
    Array<float> h(2);
    Array<double> j(3);
    int *g = new int();
    Awesome tab2[5];
    


    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i;
    for (unsigned int i = 0; i < b.size(); i++)
        b[i] = i + 1;
    for (unsigned int i = 0; i < c.size(); i++) {
        std::stringstream ss;
        ss << "string" << i;
        c[i] = ss.str();
    }
    for (unsigned int i = 0; i < h.size(); i++)
        h[i] = i + 42.19f;
    for (unsigned int i = 0; i < j.size(); i++)
        j[i] = i + 3000.42;
    
    d = a;
    Array<int> e(b);

    std::cout << "a: ";
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    std::cout << "a[6]: ";
    try {
        std::cout << a[6] << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }
    std::cout << "b: ";
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;
    std::cout << "c: ";
    for (unsigned int i = 0; i < c.size(); i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;
    std::cout << "d: (d = a) ";
    for (unsigned int i = 0; i < d.size(); i++)
        std::cout << d[i] << " ";
    std::cout << std::endl;
    std::cout << "e: (e(b))  ";
    for (unsigned int i = 0; i < e.size(); i++)
        std::cout << e[i] << " ";
    std::cout << std::endl;
    std::cout << "f: ";
    for (unsigned int i = 0; i < f.size(); i++)
        std::cout << f[i] << " ";
    std::cout << std::endl;
    std::cout << "g: ";
    std::cout << *g << std::endl;
    std::cout << "h: ";
    for (unsigned int i = 0; i < h.size(); i++)
        std::cout << h[i] << " ";
    std::cout << std::endl;
    std::cout << "j: ";
    for (unsigned int i = 0; i < j.size(); i++)
        std::cout << j[i] << " ";
    std::cout << std::endl;
    for (unsigned int i = 0; i < 5; i++)
        std::cout << "tab2[" << i << "]: " << tab2[i] << " ";
    std::cout << std::endl;

    delete g;
    return 0;
}
