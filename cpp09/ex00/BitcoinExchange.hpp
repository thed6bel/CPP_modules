/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:31:31 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/26 16:59:07 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cfloat>

class BitcoinExchange
{
private:
    std::ifstream       _file;
    std::string         _filename;
    std::map<std::string, double>  _values;
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& filename);
    BitcoinExchange(const BitcoinExchange& copy);
    ~BitcoinExchange();
    void    readData();
    bool    checkLineFormat(std::string& line);
    bool    strdigit(std::string str);
    void    result(BitcoinExchange& fd);
    double  getRate(std::string date);
    std::string decreaseDate(std::string date);
    int controlDoubleDate(std::map<std::string, double> data, std::string date);
    int controlEmptyValue(std::string value);

    BitcoinExchange& operator=(const BitcoinExchange& rhs);
};
