/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:48:17 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/17 12:56:29 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N), _count(0) {
    _arr = new int[N];
}

Span::Span(const Span &copy) {
    *this = copy;
}

Span &Span::operator=(const Span &copy) {
    if (this != &copy) {
        _N = copy._N;
        _count = copy._count;
        _arr = copy._arr;
    }
    return *this;
}

Span::~Span() {
    delete [] _arr;
}

void Span::addNumber(int n) {
    if (_count >= _N)
        throw FullArrayException();
    _arr[_count] = n;
    _count++;
}

int Span::shortestSpan() {
    if (_count <= 1)
        throw NotEnoughElementsException();
    std::sort(_arr, _arr + _count);
    int min = _arr[1] - _arr[0];
    for (unsigned int i = 2; i < _count; i++) {
        if (_arr[i] - _arr[i - 1] < min)
            min = _arr[i] - _arr[i - 1];
    }
    return min;
}

int Span::longestSpan() {
    if (_count <= 1)
        throw NotEnoughElementsException();
    std::sort(_arr, _arr + _count);
    return _arr[_count - 1] - _arr[0];
}

const char* Span::FullArrayException::what() const throw() {
    return "Array is full";
}

const char* Span::NotEnoughElementsException::what() const throw() {
    return "Not enough elements";
}
