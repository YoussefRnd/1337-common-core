/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:10:11 by yboumlak          #+#    #+#             */
/*   Updated: 2025/07/16 22:48:17 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() : vectorTime(0.0), dequeTime(0.0) {}

PmergeMe::PmergeMe(const PmergeMe &other) : vec(other.vec), deq(other.deq), vectorTime(other.vectorTime), dequeTime(other.dequeTime) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    this->vec = other.vec;
    this->deq = other.deq;
    this->vectorTime = other.vectorTime;
    this->dequeTime = other.dequeTime;
  }
  return *this;
}

bool PmergeMe::isValidInput(const std::string &str) {
  if (str.empty()) return false;

  for (size_t i = 0; i < str.size(); ++i) {
    if (!std::isdigit(str[i])) return false;
  }

  int num = std::atoi(str.c_str());
  return num > 0;
}

bool PmergeMe::hasNoDuplicates(const std::vector<int> &numbers) {
  for (size_t i = 0; i < numbers.size(); ++i) {
    for (size_t j = i + 1; j < numbers.size(); ++j) {
      if (numbers[i] == numbers[j]) return false;
    }
  }
  return true;
}

void PmergeMe::processInput(int argc, char **argv) {
  std::vector<int> numbers;

  for (int i = 1; i < argc; ++i) {
    if (!isValidInput(argv[i])) {
      throw std::runtime_error("Invalid input: not a positive integer");
    }
    numbers.push_back(std::atoi(argv[i]));
  }

  if (!hasNoDuplicates(numbers)) {
    throw std::runtime_error("Duplicate numbers found");
  }

  vec = numbers;
  deq.assign(numbers.begin(), numbers.end());
}

std::vector<int> PmergeMe::generateJacobsthalSequence(int maxIndex) {
  std::vector<int> jacobsthal;
  jacobsthal.push_back(0);
  jacobsthal.push_back(1);

  while (jacobsthal.back() < maxIndex) {
    int next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
    jacobsthal.push_back(next);
  }
  return jacobsthal;
}

int PmergeMe::binarySearchInsert(std::vector<int> &chain, int value, int maxPos) {
  int left = 0, right = std::min(maxPos, (int)chain.size());

  while (left < right) {
    int mid = (left + right) / 2;
    if (chain[mid] < value)
      left = mid + 1;
    else
      right = mid;
  }

  chain.insert(chain.begin() + left, value);
  return left;
}

int PmergeMe::binarySearchInsert(std::deque<int> &chain, int value, int maxPos) {
  int left = 0, right = std::min(maxPos, (int)chain.size());

  while (left < right) {
    int mid = (left + right) / 2;
    if (chain[mid] < value)
      left = mid + 1;
    else
      right = mid;
  }

  chain.insert(chain.begin() + left, value);
  return left;
}

void PmergeMe::fordJohnsonSort(std::vector<int> &container) {
  if (container.size() <= 1) return;
  if (container.size() == 2) {
    if (container[0] > container[1]) {
      std::swap(container[0], container[1]);
    }
    return;
  }

  std::vector<std::pair<int, int> > pairs;
  bool hasStraggler = false;
  int straggler = 0;

  for (size_t i = 0; i + 1 < container.size(); i += 2) {
    int first = container[i];
    int second = container[i + 1];
    if (first > second) {
      pairs.push_back(std::make_pair(second, first));
    } else {
      pairs.push_back(std::make_pair(first, second));
    }
  }

  if (container.size() % 2 == 1) {
    hasStraggler = true;
    straggler = container.back();
  }

  std::vector<int> largerElements;
  for (size_t i = 0; i < pairs.size(); ++i) {
    largerElements.push_back(pairs[i].second);
  }

  fordJohnsonSort(largerElements);

  std::vector<int> smallerPartner(largerElements.size());
  for (size_t i = 0; i < largerElements.size(); ++i) {
    for (size_t j = 0; j < pairs.size(); ++j) {
      if (pairs[j].second == largerElements[i]) {
        smallerPartner[i] = pairs[j].first;
        break;
      }
    }
  }

  std::vector<int> mainChain;
  std::vector<int> pendingElements;

  if (!largerElements.empty()) {
    mainChain.push_back(largerElements[0]);
  }

  if (!largerElements.empty()) {
    pendingElements.push_back(smallerPartner[0]);
  }

  for (size_t i = 1; i < largerElements.size(); ++i) {
    mainChain.push_back(largerElements[i]);
    pendingElements.push_back(smallerPartner[i]);
  }

  if (!pendingElements.empty()) {
    binarySearchInsert(mainChain, pendingElements[0], 1);
  }

  if (pendingElements.size() > 1) {
    std::vector<int> jacobsthal = generateJacobsthalSequence(pendingElements.size() - 1);
    std::vector<bool> inserted(pendingElements.size(), false);
    inserted[0] = true;

    for (size_t i = 1; i < jacobsthal.size(); ++i) {
      int jacobsthalIndex = jacobsthal[i];
      if (jacobsthalIndex >= (int)pendingElements.size()) {
        jacobsthalIndex = pendingElements.size() - 1;
      }

      int prevJacobsthal = (i > 1) ? jacobsthal[i - 1] : 0;

      for (int j = jacobsthalIndex; j > prevJacobsthal; --j) {
        if (j < (int)pendingElements.size() && !inserted[j]) {
          int valueToInsert = pendingElements[j];
          int largerElementPartner = largerElements[j];

          int maxPos = 0;
          for (size_t k = 0; k < mainChain.size(); ++k) {
            if (mainChain[k] == largerElementPartner) {
              maxPos = k;
              break;
            }
          }

          binarySearchInsert(mainChain, valueToInsert, maxPos);
          inserted[j] = true;
        }
      }
    }
  }

  if (hasStraggler) {
    binarySearchInsert(mainChain, straggler, mainChain.size());
  }

  container = mainChain;
}

void PmergeMe::fordJohnsonSort(std::deque<int> &container) {
  if (container.size() <= 1) return;
  if (container.size() == 2) {
    if (container[0] > container[1]) {
      std::swap(container[0], container[1]);
    }
    return;
  }

  std::deque<std::pair<int, int> > pairs;
  bool hasStraggler = false;
  int straggler = 0;

  for (size_t i = 0; i + 1 < container.size(); i += 2) {
    int first = container[i];
    int second = container[i + 1];
    if (first > second) {
      pairs.push_back(std::make_pair(second, first));
    } else {
      pairs.push_back(std::make_pair(first, second));
    }
  }

  if (container.size() % 2 == 1) {
    hasStraggler = true;
    straggler = container.back();
  }

  std::deque<int> largerElements;
  for (size_t i = 0; i < pairs.size(); ++i) {
    largerElements.push_back(pairs[i].second);
  }

  fordJohnsonSort(largerElements);

  std::deque<int> smallerPartner(largerElements.size());
  for (size_t i = 0; i < largerElements.size(); ++i) {
    for (size_t j = 0; j < pairs.size(); ++j) {
      if (pairs[j].second == largerElements[i]) {
        smallerPartner[i] = pairs[j].first;
        break;
      }
    }
  }

  std::deque<int> mainChain;
  std::deque<int> pendingElements;

  if (!largerElements.empty()) {
    mainChain.push_back(largerElements[0]);
  }
  if (!largerElements.empty()) {
    pendingElements.push_back(smallerPartner[0]);
  }
  for (size_t i = 1; i < largerElements.size(); ++i) {
    mainChain.push_back(largerElements[i]);
    pendingElements.push_back(smallerPartner[i]);
  }

  if (!pendingElements.empty()) {
    binarySearchInsert(mainChain, pendingElements[0], 1);
  }

  if (pendingElements.size() > 1) {
    std::vector<int> jacobsthal = generateJacobsthalSequence(pendingElements.size() - 1);
    std::vector<bool> inserted(pendingElements.size(), false);
    inserted[0] = true;

    for (size_t i = 1; i < jacobsthal.size(); ++i) {
      int jacobsthalIndex = jacobsthal[i];
      if (jacobsthalIndex >= (int)pendingElements.size()) {
        jacobsthalIndex = pendingElements.size() - 1;
      }

      int prevJacobsthal = (i > 1) ? jacobsthal[i - 1] : 0;

      for (int j = jacobsthalIndex; j > prevJacobsthal; --j) {
        if (j < (int)pendingElements.size() && !inserted[j]) {
          int valueToInsert = pendingElements[j];
          int largerElementPartner = largerElements[j];

          int maxPos = 0;
          for (size_t k = 0; k < mainChain.size(); ++k) {
            if (mainChain[k] == largerElementPartner) {
              maxPos = k;
              break;
            }
          }

          binarySearchInsert(mainChain, valueToInsert, maxPos);
          inserted[j] = true;
        }
      }
    }
  }
  if (hasStraggler) {
    binarySearchInsert(mainChain, straggler, mainChain.size());
  }

  container = mainChain;
}

void PmergeMe::sortAndTime() {
  std::cout << "Before: ";
  for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  clock_t start = clock();
  fordJohnsonSort(vec);
  clock_t end = clock();
  vectorTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

  start = clock();
  fordJohnsonSort(deq);
  end = clock();
  dequeTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::displayResults() {
  std::cout << "After:  ";
  for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << "Time to process a range of " << vec.size()
            << " elements with std::vector : " << vectorTime << " us" << std::endl;
  std::cout << "Time to process a range of " << vec.size()
            << " elements with std::deque   : " << dequeTime << " us" << std::endl;
}
