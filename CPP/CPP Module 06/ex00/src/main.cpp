/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:40:24 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/04 22:13:03 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../inc/ScalarConverter.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <value>" << '\n';
    return 1;
  }
  std::string input(argv[1]);
  ScalarConverter::convert(input);
  return 0;
}