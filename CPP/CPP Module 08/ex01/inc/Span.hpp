/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:50:15 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/12 02:51:01 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stdexcept>

class Span {
  private:
    std::vector<int> vector;
    unsigned int N;

  public:
    // Constructors
    Span();
    Span(unsigned int N);

    // Destructor
    ~Span();

    // Copy Constructor
    Span(const Span &src);

    // Assignation Operator
    Span &operator=(const Span &src);

    // Member Functions
    void addNumber(int n);
    int shortestSpan();
    int longestSpan();

    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end) {
      if (std::distance(begin, end) + vector.size() > N)
        throw std::runtime_error("No more space");

      vector.insert(vector.end(), begin, end);
    }
};
