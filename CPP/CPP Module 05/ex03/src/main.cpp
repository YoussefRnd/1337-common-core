/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:21:49 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/31 02:37:50 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../inc/AForm.hpp"
#include "../inc/Intern.hpp"

int main() {
  Intern intern;

  AForm *form1 = intern.makeForm("shrubbery creation", "Home");
  AForm *form2 = intern.makeForm("robotomy request", "Bender");
  AForm *form3 = intern.makeForm("presidential pardon", "Zaphod");
  AForm *form4 = intern.makeForm("unknown form", "Target");
  if (form4) {
    delete form4;
  }

  delete form1;
  delete form2;
  delete form3;

  return 0;
}
