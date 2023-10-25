/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/25 11:58:01 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int controlDoubleDate(std::map<std::string, double> data, std::string date) {
    for (std::map<std::string, double>::iterator it = data.begin(); it != data.end(); ++it) {
        if (it->first == date)
            return 1;
    }
    return 0;
}

int controlEmptyValue(std::string value) {
    if (value == "" || value.find_first_not_of(" \t\n\v\f\r"))
        return 1;
    return 0;
}

int controlValidDate(std::string date) {
    std::string delimiter = "-", token;
    size_t pos = 0;
    int i = 0;
    int year, month, day, daysInMonth, leapYear;

    if (date[4] != '-' || date[7] != '-')
        return 1;
    while ((pos = date.find(delimiter)) && i < 3) {
        token = date.substr(0, pos);
        if (i == 0) {
            year = atoi(token.c_str());
            if (year < 2009 || year > 2050)
                return 1;
        } else if (i == 1) {
            month = atoi(token.c_str());
            if (month < 1 || month > 12)
                return 1;
        } else if (i == 2) {
            day = atoi(token.c_str());
            if (day < 1)
                return 1;
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
            if (day > daysInMonth)
                return 1;
        }
        date.erase(0, pos + delimiter.length());
        i++;
    }
    return 0;
}

int controlValue(std::string value) {
    std::string delimiter = ".", token;
    size_t pos = 0;
    int i = 0;

    double tmp = strtod(value.c_str(), NULL);
    if (tmp > DBL_MAX)
        return 1;
    while ((pos = value.find(delimiter)) && i < 2) {
        token = value.substr(0, pos);
        for (int j = 0; token[j] != '\0'; j++) {
            if (!isdigit(token[j]))
                return 1;
        }
        if (i == 0) {
            if (strtod(value.c_str(), NULL) < 0) {
                return 1;
            }
        } else if (i == 1) {
            if (strtod(value.c_str(), NULL) < 0)
                return 1;
        }
        value.erase(0, pos + delimiter.length());
        i++;
    }
    return 0;
}

std::map<std::string, double> readData() {
    std::ifstream file("data.csv");
    std::string line;
    std::map<std::string, double> data;
    std::string date;
    double value;
    std::string delimiter = ",";
    size_t pos = 0;
    int i = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (i == 0 ) {
                if (line != "date,exchange_rate") {
                    std::cout << "Error: Bad header format on *.csv" << std::endl;
                    exit(1);
                }
                i++;
                continue;
            }
            if (line[10] != ',') {
                std::cout << "Error: Bad date or value format on *.csv" << std::endl;
                exit(1);
            }
            pos = line.find(delimiter);
            date = line.substr(0, pos);
            if (controlEmptyValue(date) || controlValidDate(date)) {
                std::cout << "Error: Empty date, bad date format or bad date input on *.csv => " << date << std::endl;
                exit(1);
            }
            line.erase(0, pos + delimiter.length());
            if (controlEmptyValue(line)) {
                std::cout << "Error: Empty value or bad value" << std::endl;
                exit(1);
            }
            if (controlDoubleDate(data, date)) {
                std::cout << "Error: Double date on *.csv input file" << std::endl;
                exit(1);
            }
            if (controlValue(line)) {
                std::cout << "Error: Empty value or bad value on *.csv input file" << std::endl;
                exit(1);
            }
            value = strtod(line.c_str(), NULL);
            data[date] = value;
            i++;
        } file.close();
    } else
        std::cout << "Error: Unable to open file" << std::endl;
    if (data.size() == 0) {
        std::cout << "Error: Empty *.csv input file" << std::endl;
        exit(1);
    }
    return data;
}

int	main(int argc, char **argv){

    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        exit(1);
    }

    BitcoinExchange bitcoinExchange(argv[1]);
    std::map<std::string, double> data = readData();
    for (std::map<std::string, double>::iterator it = data.begin(); it != data.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    return 0;
}
