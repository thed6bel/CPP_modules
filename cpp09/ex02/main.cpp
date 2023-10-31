/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:45 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/31 10:57:04 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// void insertionSort(std::deque<int>& arr, int low, int high) {
//     for (int i = low + 1; i <= high; i++) {
//         int key = arr[i];
//         int j = i - 1;
        
//         while (j >= low && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j--;
//         }
        
//         arr[j + 1] = key;
//     }
// }

// void merge(std::deque<int>& arr, int low, int mid, int high) {
//     int n1 = mid - low + 1;
//     int n2 = high - mid;
    
//     std::deque<int> left(n1);
//     std::deque<int> right(n2);
    
//     for (int i = 0; i < n1; i++) {
//         left[i] = arr[low + i];
//     }
    
//     for (int j = 0; j < n2; j++) {
//         right[j] = arr[mid + 1 + j];
//     }
    
//     int i = 0, j = 0, k = low;
    
//     while (i < n1 && j < n2) {
//         if (left[i] <= right[j]) {
//             arr[k] = left[i];
//             i++;
//         } else {
//             arr[k] = right[j];
//             j++;
//         }
//         k++;
//     }
    
//     while (i < n1) {
//         arr[k] = left[i];
//         i++;
//         k++;
//     }
    
//     while (j < n2) {
//         arr[k] = right[j];
//         j++;
//         k++;
//     }
// }

// void fordJohnsonMergeInsert(std::deque<int>& arr, int low, int high) {
//     if (low < high) {
//         if (high - low + 1 <= 10) {
//             insertionSort(arr, low, high);
//         } else {
//             int mid = low + (high - low) / 2;
//             fordJohnsonMergeInsert(arr, low, mid);
//             fordJohnsonMergeInsert(arr, mid + 1, high);
//             merge(arr, low, mid, high);
//         }
//     }
// }

// int main() {
//     std::deque<int> vec;
//     vec.push_back(9);
//     vec.push_back(2);
//     vec.push_back(5);
//     vec.push_back(1);
//     vec.push_back(7);
//     vec.push_back(4);
//     vec.push_back(8);
//     vec.push_back(3);
//     vec.push_back(6);

//     fordJohnsonMergeInsert(vec, 0, vec.size() - 1);

//     std::cout << "Liste triée : ";
//     for (std::deque<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }

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