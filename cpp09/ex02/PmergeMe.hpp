/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:53:41 by thed6bel          #+#    #+#             */
/*   Updated: 2023/10/31 10:00:56 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sys/time.h>
#include <algorithm>

class PmergeMe {
    private:
        std::vector<int>    _intVector;
        std::deque<int>     _intDeque;
        PmergeMe();
    public:
        PmergeMe(char** arg);
        PmergeMe(const PmergeMe &copy);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &copy);
        static bool invalidArg(char **args, int argc);
        template<typename T>
        T       FJ_MergeSort(T container);
        void    startShort();
};