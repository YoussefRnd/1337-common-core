/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:17:00 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/11 02:05:32 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../inc/Span.hpp"

int main() {
  std::cout << "Test 1" << std::endl;
  Span sp = Span(5);

  try {
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(110);
  } catch (std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "Test 2" << std::endl;
  Span sp2 = Span(10000);
  std::srand(std::time(NULL));
  std::vector<int> randomNumbers;
  for (int i = 0; i < 10000; i++) {
    randomNumbers.push_back(std::rand() % 10000);
  }

  try {
    sp2.addNumbers(randomNumbers.begin(), randomNumbers.end());
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}