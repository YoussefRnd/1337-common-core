/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:13:29 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/11 00:39:46 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>

// Constructors
Span::Span() : N(0) {}
Span::Span(unsigned int N) : N(N) {}

// Destructor
Span::~Span() {}

// Copy Constructor
Span::Span(const Span &src) {
  *this = src;
}

// Assignation Operator
Span &Span::operator=(const Span &src) {
  if (this != &src) {
    this->vector = src.vector;
    this->N = src.N;
  }
  return *this;
}

// Member Functions
void Span::addNumber(int n) {
  if (vector.size() < N)
    vector.push_back(n);
  else
    throw std::runtime_error("No more space");
}

int Span::shortestSpan() {
  if (vector.size() < 2)
    throw std::runtime_error("Not enough elements");

  std::sort(vector.begin(), vector.end());

  int minSpan = std::numeric_limits<int>::max();
  for (size_t i = 1; i < vector.size(); ++i) {
    int span = vector[i] - vector[i - 1];
    if (span < minSpan)
      minSpan = span;
  }
  return minSpan;
}

int Span::longestSpan() {
  if (vector.size() < 2)
    throw std::runtime_error("Not enough elements");

  int minElement = *std::min_element(vector.begin(), vector.end());
  int maxElement = *std::max_element(vector.begin(), vector.end());

  return maxElement - minElement;
}
