/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 03:27:37 by yboumlak          #+#    #+#             */
/*   Updated: 2025/06/30 17:20:30 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : operands(other.operands) {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other) {
  if (this != &other) {
    this->operands = other.operands;
  }
  return *this;
}

std::stack<int> RPN::getOperands() const {
  return operands;
}

std::vector<std::string> RPN::split(const std::string &str, char delimiter) {
  std::vector<std::string> tokens;
  std::istringstream stream(str);
  std::string token;

  while (std::getline(stream, token, delimiter)) {
    tokens.push_back(token);
  }

  return tokens;
}

bool RPN::isOperator(const std::string &token) {
  return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isNumber(const std::string &token) {
  if (token.empty())
    return false;
  for (size_t i = 0; i < token.size(); ++i) {
    if (!std::isdigit(token[i]))
      return false;
  }
  return true;
}

bool RPN::evaluate(const std::vector<std::string> &tokens) {
  for (size_t i = 0; i < tokens.size(); i++) {
    if (isNumber(tokens[i])) {
      std::istringstream ss(tokens[i]);
      int number;
      ss >> number;
      operands.push(number);
    } else if (isOperator(tokens[i])) {
      if (operands.size() < 2) {
        std::cerr << "Error: Not enough operands" << std::endl;
        return false;
      }
      int b = operands.top();
      operands.pop();
      int a = operands.top();
      operands.pop();
      int result;

      switch (tokens[i][0]) {
        case '+':
          result = a + b;
          break;
        case '-':
          result = a - b;
          break;
        case '*':
          result = a * b;
          break;
        case '/':
          if (b == 0) {
            std::cerr << "Error: Division by zero" << std::endl;
            return false;
          }
          result = a / b;
          break;
        default:
          std::cerr << "Error: Unknown operator" << std::endl;
          return false;
      }
      operands.push(result);
    } else {
      std::cerr << "Error: Invalid token" << std::endl;
      return false;
    }
  }
  return true;
}
