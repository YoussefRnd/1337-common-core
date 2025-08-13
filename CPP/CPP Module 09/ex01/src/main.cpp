/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:29:35 by yboumlak          #+#    #+#             */
/*   Updated: 2025/06/30 17:34:07 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
    return 1;
  }

  RPN rpn;
  std::string expression = argv[1];
  std::vector<std::string> tokens = rpn.split(expression, ' ');

  if (!rpn.evaluate(tokens)) {
    return 1;
  }

  if (rpn.getOperands().size() == 1) {
    std::cout << rpn.getOperands().top() << std::endl;
  } else {
    std::cerr << "Error: Invalid expression" << std::endl;
    return 1;
  }

  return 0;
}