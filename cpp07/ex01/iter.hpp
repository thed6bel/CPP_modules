/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:51:21 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/11 09:54:50 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
void iter(T *array, int length, void (*f)(T const &)){
    for (int i = 0; i < length; i++)
        f(array[i]);
}

template <typename T>
void print(T const &x){
    std::cout << x << std::endl;
}
