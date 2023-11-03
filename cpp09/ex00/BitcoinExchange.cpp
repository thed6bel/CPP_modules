/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:31:28 by hucorrei          #+#    #+#             */
/*   Updated: 2023/11/03 14:18:48 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    _file.open("data.csv");
    _filename = "data.csv";
    if (!_file.is_open())
        throw std::runtime_error("Error: could not open file \"data.csv\".");
}

BitcoinExchange::BitcoinExchange(const std::string& filename)
{
    _file.open(filename.c_str());
    _filename = filename;
    if (!_file.is_open())
        throw std::runtime_error("Error: could not open file \"" + filename + "\".");
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    _file.open(copy._filename.c_str());
    _filename = copy._filename;
    _values = std::map<std::string, double>(copy._values.begin(), copy._values.end());
    if (!_file.is_open())
        throw std::runtime_error("Error: could not open file \"" + _filename + "\".");
}

BitcoinExchange::~BitcoinExchange()
{
    if (_file.is_open())
        _file.close();
}

void BitcoinExchange::readData() {
    std::string line, date;
    double      value;
    size_t      i;

    i = 0;
    while (std::getline(_file, line)) {
        if (i == 0 ) {
            if (line != "date,exchange_rate") {
                std::cout << "Error: Bad header format on *.csv" << std::endl;
                exit(1);
            }
            i++;
            continue;
        } if (line[10] != ',') {
            std::cout << "Error: Bad date or value format on *.csv" << std::endl;
            exit(1);
        }
        date = "";
        value = 0;
        if (line.find_first_of(",") != std::string::npos) {
            date = line.substr(0, line.find_first_of(",")).c_str();
            value = atof(line.substr(line.find_first_of(",") + 1).c_str());
        } if (controlEmptyValue(date)) {
			std::cout << "Error: Empty date" << std::endl;
			exit(1);
		} if (checkLineFormat(line))
            exit(1);
        if (controlEmptyValue(line)) {
            std::cout << "Error: Empty value or bad value" << std::endl;
            exit(1);
        } 
		if (controlDoubleDate(this->_values, date)) {
            std::cout << "Error: Double date on *.csv input file" << std::endl;
            exit(1);
        } 
		if (!line[11]) {
			std::cout << "Error: Empty value on *.csv input file" << std::endl;
			exit(1);
		}
        std::pair<std::string, double> data(date, value);
        _values.insert(data);
    } if (this->_values.size() == 0) {
        std::cout << "Error: Empty *.csv input file" << std::endl;
        exit(1);
    }
}

bool BitcoinExchange::checkLineFormat(std::string &line) {
    int    year, month, day, daysInMonth, leapYear;
    double rate;

    if (line.size() < 12 || line[4] != '-' || line[7] != '-' || !strdigit(line.substr(line.find_first_of("|,") + 1))) {
        std::cout << "Error: bad input => " << line.substr(0, line.find_first_of("|")).c_str() << std::endl;
        return true;
    }
    year = std::atoi(line.substr(0, line.find("-")).c_str());
    if (year < 1 || year > 9999) {
        std::cout << "Error: bad input => " << line.substr(0, line.find_first_of("|")).c_str() << std::endl;
        return true;
    }
    month = std::atoi(line.substr(5).c_str());
    if (month < 1 || month > 12) {
        std::cout << "Error: bad input => " << line.substr(0, line.find_first_of("|")).c_str() << std::endl;
        return true;
    }
    day = std::atoi(line.substr(8).c_str());
        if (day < 1) {
            std::cout << "Error: not a positive number." << std::endl;
            return 1;
        }
        if (month == 2) {
            leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if (leapYear)
                daysInMonth = 29;
            else
                daysInMonth = 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11)
            daysInMonth = 30;
        else
            daysInMonth = 31;
        if (day > daysInMonth) {
            std::cout << "Error: bad input => " 
				<< std::setw(4) << std::setfill('0') << year << "-" 
				<< std::setw(2) << std::setfill('0') << month << "-" 
				<< std::setw(2) << std::setfill('0') << day << std::endl;
            return 1;
        }
    rate = std::atof(line.substr(line.find_first_of("|,") + 1).c_str());
    if (rate < 0 || rate > 2147483647 || rate < -2147483648) {
        if (rate < 0)
            std::cout << "Error: not a positive number." << std::endl;
        else
            std::cout << "Error: too large a number." << std::endl;
        return true;
    }
    if ((year == 2009 && month == 1 && day == 1) || year < 2009) {
        std::cout << "Error: date before the creation of btc on data base => " 
			<< std::setw(4) << std::setfill('0') << year << "-" 
			<< std::setw(2) << std::setfill('0') << month << "-" 
			<< std::setw(2) << std::setfill('0') << day << std::endl;
        return true;
    }
    return false;
}

bool BitcoinExchange::strdigit(std::string str)
{
    int decimal_point;

    decimal_point = 0;
    if (str[0] == ' ')
        str = str.substr(1);
    for (int i = 0; str[i]; i++) {
        if (std::isdigit(str[i]))
            continue ;
        else if ((i == 0 && str[i] == '-') || (str[i] == '.' && !decimal_point++))
            continue ;
        return false;
    }
    return true;
}

void BitcoinExchange::result(BitcoinExchange &fd) {
	std::string	line, date, date_tmp;
	double		value, rate;
	size_t		i;

	i = 0;
	while (std::getline(fd._file, line)) {
		if (i == 0 ) {
			if (line != "date | value") {
				std::cout << "Error: Bad header format on input file" << std::endl;
				exit(1);
			}
			i++;
			continue ;
		}
		if (checkLineFormat(line))
			continue ;
        if (line[11] != '|' || line[13] == '\0') {
            std::cout << "Error: Bad input => " << line << std::endl;
            continue ;
        }
		date = line.substr(0, line.find_first_of("|") - 1).c_str();
		value = atof(line.substr(line.find_first_of("|") + 1).c_str());
        if (value >= 1001) {
            std::cout << "Error: maximum value is exceeded => " << line << std::endl;
            continue ;
        }

        date_tmp = date;
		rate = getRate(date_tmp);
		while (rate < 0) {
			date_tmp = decreaseDate(date_tmp);
			rate = getRate(date_tmp);
		}
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
}

double BitcoinExchange::getRate(std::string date)
{
    std::map<std::string, double>::iterator it;

    for (it = _values.begin(); it != _values.end(); it++)
        if (date == it->first)
            return it->second;
    return -1;
}

std::string BitcoinExchange::decreaseDate(std::string date) {
    std::istringstream iss(date);
    int year, month, day;
    char separator;

	std::map<std::string, double>::reverse_iterator rit = _values.rbegin();
	std::string date_tmp = rit->first;
	if (date_tmp < date)
		return date_tmp;
    if (!(iss >> year >> separator >> month >> separator >> day)) {
        std::cout << "Invalid date format" << std::endl;;
    }
    if (day == 1) {
        if (month == 1) {
            year--;
            month = 12;
        }
        else {
            month--;
        }
        day = 31;
    }
    else {
        day--;
    }
    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << year << separator
        << std::setw(2) << std::setfill('0') << month << separator
        << std::setw(2) << std::setfill('0') << day;
    return oss.str();
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs) {
        _file.open(rhs._filename.c_str());
        _filename = rhs._filename;
        _values = std::map<std::string, double>(rhs._values.begin(), rhs._values.end());
        if (!_file.is_open())
            throw std::runtime_error("Error: could not open file \"" + _filename + "\".");
    }
    return *this;
}

bool BitcoinExchange::controlDoubleDate(std::map<std::string, double> data, std::string date) {
    for (std::map<std::string, double>::iterator it = data.begin(); it != data.end(); ++it) {
        if (it->first == date)
            return true;
    }
    return false;
}

bool BitcoinExchange::controlEmptyValue(std::string value) {
    if (value == "" || value.find_first_not_of(" \t\n\v\f\r"))
        return true;
    return false;
}
