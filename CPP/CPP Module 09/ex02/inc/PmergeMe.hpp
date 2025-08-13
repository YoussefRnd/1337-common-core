/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:42:49 by yboumlak          #+#    #+#             */
/*   Updated: 2025/07/16 22:39:24 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

class PmergeMe {
  private:
    std::vector<int> vec;
    std::deque<int> deq;
    double vectorTime;
    double dequeTime;

    void fordJohnsonSort(std::vector<int> &container);
    void fordJohnsonSort(std::deque<int> &container);

    std::vector<int> generateJacobsthalSequence(int maxIndex);
    int binarySearchInsert(std::vector<int> &chain, int value, int maxPos);
    int binarySearchInsert(std::deque<int> &chain, int value, int maxPos);


  public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &other);

    void processInput(int argc, char **argv);
    void sortAndTime();
    void displayResults();

    bool isValidInput(const std::string &str);
    bool hasNoDuplicates(const std::vector<int> &numbers);
};
