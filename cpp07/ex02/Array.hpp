/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:02:44 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/17 11:38:29 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
class Array
{
    private:
        T	*_arr;
        unsigned int	_n;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &obj);
        Array &operator = (const Array &obj);
        T &operator [] (unsigned int i);
        unsigned int size() const;
        ~Array();
};

template <typename T>
Array<T>::Array() {
	this->_arr = NULL;
	this->_n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->_arr = new T[n];
	this->_n = n;
}

template <typename T>
Array<T>::Array(const Array &obj) {
	this->_arr = new T[obj._n];
	this->_n = obj._n;
	for (unsigned int i = 0; i < obj._n; i++)
		this->_arr[i] = obj._arr[i];
}

template <typename T>
Array<T> &Array<T>::operator = (const Array &obj) {
	if (this->_arr)
		delete [] this->_arr;
	this->_arr = new T[obj._n];
	this->_n = obj._n;
	for (unsigned int i = 0; i < obj._n; i++)
		this->_arr[i] = obj._arr[i];
	return *this;
}

template <typename T>
T &Array<T>::operator [] (unsigned int i) {
	if (i >= this->_n)
		throw std::out_of_range("out of range");
	return this->_arr[i];
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->_n;
}

template <typename T>
Array<T>::~Array() {
	if (this->_arr)
		delete [] this->_arr;
}
