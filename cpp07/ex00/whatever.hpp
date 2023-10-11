/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:24:59 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/11 09:32:28 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
void swap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
const T min(const T a, const T b){
    if (a < b)
        return a;
    return b;
}

template <typename T>
const T max(const T a, const T b){
    if (a > b)
        return a;
    return b;
}
