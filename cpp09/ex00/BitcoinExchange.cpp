/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:31:28 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/25 11:46:55 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    _file.open("data.csv");
    _name = "data.csv";
    if (!_file.is_open())
        throw std::runtime_error("\033[0;31mError: could not open file \"data.csv\".\033[0m");
}

BitcoinExchange::BitcoinExchange(std::string name) {
    _file.open(name.c_str());
    _name = name;
    if (!_file.is_open())
        throw std::runtime_error("\033[0;31mError: could not open file \"" + name + "\".\033[0m");
}

BitcoinExchange::~BitcoinExchange(void) {
    if (_file.is_open())
        _file.close();
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &obj) {
    if (this != &obj) {
        _file.open(obj._name.c_str());
        _name = obj._name;
        _values = std::map<std::string, double>(obj._values.begin(), obj._values.end());
        if (!_file.is_open())
            throw std::runtime_error("\033[0;31mError: could not open file \"" + _name + "\".\033[0m");
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj) {
    *this = obj;
}
