/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:33:17 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/18 12:05:56 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
    private:
        unsigned int		_N;
        unsigned int		_count;
        int					*_arr;
        Span();
    public:
        Span(unsigned int N);
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span();
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        class FullArrayException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NotEnoughElementsException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};