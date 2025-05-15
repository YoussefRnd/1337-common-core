/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:57:19 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/26 23:45:37 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../inc/Bureaucrat.hpp"

int main() {
  Bureaucrat bureaucrat("Youssef", 150);
  try {
    std::cout << bureaucrat;
    bureaucrat.decrementGrade();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}