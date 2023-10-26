/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/26 16:59:31 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// std::map<std::string, double> readData() {
//     std::ifstream file("data.csv");
//     std::string line;
//     std::map<std::string, double> data;
//     std::string date;
//     double value;
//     std::string delimiter = ",";
//     size_t pos = 0;
//     int i = 0;

//     if (file.is_open()) {
//         while (getline(file, line)) {
//             if (i == 0 ) {
//                 if (line != "date,exchange_rate") {
//                     std::cout << "Error: Bad header format on *.csv" << std::endl;
//                     exit(1);
//                 }
//                 i++;
//                 continue;
//             }
//             if (line[10] != ',') {
//                 std::cout << "Error: Bad date or value format on *.csv" << std::endl;
//                 exit(1);
//             }
//             pos = line.find(delimiter);
//             date = line.substr(0, pos);
//             if (controlEmptyValue(date) || controlValidDate(date)) {
//                 std::cout << "Error: Empty date, bad date format or bad date input on *.csv => " << date << std::endl;
//                 exit(1);
//             }
//             line.erase(0, pos + delimiter.length());
//             if (controlEmptyValue(line)) {
//                 std::cout << "Error: Empty value or bad value" << std::endl;
//                 exit(1);
//             }
//             if (controlDoubleDate(data, date)) {
//                 std::cout << "Error: Double date on *.csv input file" << std::endl;
//                 exit(1);
//             }
//             if (controlValue(line)) {
//                 std::cout << "Error: Empty value or bad value on *.csv input file" << std::endl;
//                 exit(1);
//             }
//             value = strtod(line.c_str(), NULL);
//             data[date] = value;
//             i++;
//         } file.close();
//     } else
//         std::cout << "Error: Unable to open file" << std::endl;
//     if (data.size() == 0) {
//         std::cout << "Error: Empty *.csv input file" << std::endl;
//         exit(1);
//     }
//     return data;
// }

// int	main(int argc, char **argv){

//     if (argc != 2) {
//         std::cout << "Error: could not open file." << std::endl;
//         exit(1);
//     }

//     BitcoinExchange bitcoinExchange(argv[1]);
//     std::map<std::string, double> data = readData();
//     for (std::map<std::string, double>::iterator it = data.begin(); it != data.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';
//     return 0;
// }

int main(int argc, char **argv)
{
    try {
        if (argc != 2)
            throw std::runtime_error("Error: Bad arguments");
        BitcoinExchange database;
        BitcoinExchange inputfile(argv[1]);
        database.readData();
        database.result(inputfile);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}