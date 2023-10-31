/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:01:27 by thed6bel          #+#    #+#             */
/*   Updated: 2023/10/31 11:20:59 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char** arg) {
    for (int i = 0; arg[i]; i++) {
        _intVector.push_back(std::strtol(arg[i], NULL, 10));
        _intDeque.push_back(std::strtol(arg[i], NULL, 10));
    }
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
     _intVector = std::vector<int>(copy._intVector.begin(), copy._intVector.end());
    _intDeque = std::deque<int>(copy._intDeque.begin(), copy._intDeque.end());
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
    if (this != &copy) {
        this->_intVector = copy._intVector;
        this->_intDeque = copy._intDeque;
    }
    return (*this);
}

bool PmergeMe::invalidArg(char **args, int argc) {
    for (size_t i = 0; i < (size_t)argc; i++) {
        if (!args[i][0]) {
            std::cout << "Error: argument empty.";
            return true;
        }
    }
    for (size_t i = 0; args[i]; i++) {
        for (size_t j = 0; args[i][j]; j++) {
            if (!std::isdigit(args[i][j])) {
                std::cout << "Error: bad input.";
                return true;
            }
        }
        for (int j = i - 1; j >= 0; j--) {
            if (std::string(args[i]) == std::string(args[j])) {
                std::cout << "Error: double input.";
                return true;
            }
        }
        if (std::strtol(args[i], NULL, 10) > 2147483647) {
            std::cout << "Error: maximum value of an integer is reached.";
            return true;
        }
    }
    return false;
}

template<typename T>
T PmergeMe::FJ_MergeSort(T container) {
    T    right;
    T    left;
    T    result;
    if (container.size() >= 3) {
        for (size_t i = 0; i < (container.size() / 2); i++) {
            left.push_back(container[i]);
        }
        for (size_t i = (container.size() / 2); i < container.size(); i++) {
            right.push_back(container[i]);
        }
        right = FJ_MergeSort(right);
        left = FJ_MergeSort(left);
    }
    if (container.size() == 2) {
        if (container[0] > container[1]) {
            int temp = container[0];
            container[0] = container[1];
            container[1] = temp;
        }
    }
    else if (container.size() >= 3) {
        while (right.size() || left.size()) {
            if (right.size() && left.size()) {
                if (right[0] < left[0]) {
                    result.push_back(right[0]);
                    right.erase(right.begin());
                }
                else {
                    result.push_back(left[0]);
                    left.erase(left.begin());
                }
            }
            else if (right.size()) {
                result.push_back(right[0]);
                right.erase(right.begin());
            }
            else {
                result.push_back(left[0]);
                left.erase(left.begin());
            }
        }
    }
    if (container.size() < 3)
        return container;
    return result;
}

void PmergeMe::startShort() {
    double time_vector, time_deque;
    struct timeval start_time, end_time;
    std::deque<int>    temp = std::deque<int>(_intDeque.begin(), _intDeque.end());;

    std::cout << "Before:\t";
    for (size_t i = 0; i < _intVector.size(); i++) {
        std::cout << " " << _intVector[i];
    }
    std::cout << std::endl;

    gettimeofday(&start_time, NULL);
    _intVector = FJ_MergeSort(_intVector);
    gettimeofday(&end_time, NULL);
    time_vector = (end_time.tv_sec - start_time.tv_sec) * 1000.0;
    time_vector += (end_time.tv_usec - start_time.tv_usec) / 1000.0;

    std::cout << "After:\t";
    for (size_t i = 0; i < _intVector.size(); i++) {
        std::cout << " " << _intVector[i];
    }
    std::cout << std::endl;

    gettimeofday(&start_time, NULL);
    _intDeque = FJ_MergeSort(_intDeque);
    gettimeofday(&end_time, NULL);
    time_deque = (end_time.tv_sec - start_time.tv_sec) * 1000.0;
    time_deque += (end_time.tv_usec - start_time.tv_usec) / 1000.0;

    std::cout << "Time to process a range of " << _intVector.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << time_vector << " us" << std::endl;
    std::cout << "Time to process a range of " << _intDeque.size() << " elements with std::deque : " << std::fixed << std::setprecision(5) << time_deque << " us" << std::endl;
}
