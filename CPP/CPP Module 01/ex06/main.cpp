/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:04:36 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/05 15:52:04 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

int main(int argc, char **argv) {
  Harl harl;

  if (argc == 2) {
    harl.complain(std::string(argv[1]));
  } else {
    std::cout << "Invalid number of arguments\n";
  }
  return 0;
}