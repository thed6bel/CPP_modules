/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/11/03 10:17:53 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    try {
        if (argc < 2)
            throw std::runtime_error("Error: Invalid arguments size.");
        argv = &argv[1];
        if (PmergeMe::invalidArg(argv, argc - 1))
            throw std::runtime_error("");
        PmergeMe container(argv);
        container.startShort();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}