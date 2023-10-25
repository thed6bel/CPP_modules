/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:31:31 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/25 14:25:19 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

class BitcoinExchange {
    private:
        std::string                     _name;
        std::ifstream                   _file;
        std::map<std::string, double>   _values;
    public:
        BitcoinExchange();
        BitcoinExchange(std::string name);
        BitcoinExchange(BitcoinExchange const &obj);
        ~BitcoinExchange(void);
        BitcoinExchange &operator=(BitcoinExchange const &obj);
        
};
