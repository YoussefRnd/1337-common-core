/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:46:09 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/05 15:49:59 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

void Harl::debug(void) {
  std::cout << "[ DEBUG ]\n";
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. \nI really do!\n";
}

void Harl::info(void) {
  std::cout << "[ INFO ]\n";
  std::cout << "I cannot believe adding extra bacon costs more money. \nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void) {
  std::cout << "[ WARNING ]\n";
  std::cout << "I think I deserve to have some extra bacon for free. \nI’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void) {
  std::cout << "[ ERROR ]\n";
  std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level) {
  void (Harl::*ptrs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  for (int i = 0; i < 4; i++) {
    if (levels[i] == level) {
      (this->*ptrs[i])();
      return;
    }
  }
  std::cout << "Invalid level\n";
}