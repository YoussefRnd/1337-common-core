/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:14:46 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/27 23:02:47 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main() {
  try {
    Bureaucrat john("John", 50);
    Form taxForm("Tax Form", 45, 20);

    john.signForm(taxForm);

    Bureaucrat boss("Boss", 30);
    boss.signForm(taxForm);

  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
