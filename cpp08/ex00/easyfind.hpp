/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:36:06 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/17 12:43:45 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
int easyfind(T &container, int n) {
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), n);
    if (it != container.end())
        return *it;
    else
        throw std::exception();
}