/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/15 11:20:48 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv){
	if (argc != 4){
		std::cout << "\033[1;31mError:\033[0m wrong number of arguments." << std::endl;
		std::cout << "Usage: ./replace <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	if (std::string(argv[2]).length() == 0 || std::string(argv[3]).length() == 0){
		std::cout << "\033[1;31mError:\033[0m empty string." << std::endl;
		return (1);
	}
	std::fstream file;
	file.open(argv[1], std::ios::in);
	if (!file.is_open()){
		std::cout << "\033[1;31mError:\033[0m file not found." << std::endl;
		return (1);
	}
	std::ofstream outfile(std::string(argv[1]) + ".replace");
	if (!outfile) {
		std::cout << "\033[1;31mError:\033[0m Failed to creat outfile." << std::endl;
		return 1;
	}
	std::string tmp;
	std::getline(file, tmp, '\0');
	int c = 0;
	int e = 0;
	for (unsigned int i = 0; tmp[i + c];i++){
		if ((unsigned long)c + i == tmp.find(argv[2], i + c)){
			outfile << std::string(argv[3]);
			c += (std::string(argv[2]).length() - 1);
			e++;
		}
		else
			outfile << tmp[i + c];
	}
	file.close();
	outfile.close();
	if (e != 0)
		std::cout << "\033[1;32m" << e << "\033[0m replacement(s) done." << std::endl;
	else
		std::cout << "\033[1;31mError: \033[0m" << argv[2] << " Not found" << std::endl;
	return (0);
}
