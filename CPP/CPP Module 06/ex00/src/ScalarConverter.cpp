/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:53:12 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/04 22:54:13 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

// Constructors
ScalarConverter::ScalarConverter() {}

// Destructor
ScalarConverter::~ScalarConverter() {}

// Copy Constructor
ScalarConverter::ScalarConverter(const ScalarConverter &src) {
  *this = src;
}

// Assignation Operator
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
  if (this != &src) {
    *this = src;
  }
  return *this;
}

// Static methods
Type ScalarConverter::detectType(const std::string &input) {
  if (input.empty()) {
    return INVALID;
  } else if (input.length() == 1 && !std::isdigit(input[0])) {
    return CHAR;
  }

  char *end;
  double value = std::strtod(input.c_str(), &end);

  if (std::isnan(value) || std::isinf(value)) {
    if (*end == 'f' && *(end + 1) == '\0') {
      return FLOAT;
    } else if (*end == '\0') {
      return DOUBLE;
    } else {
      return INVALID;
    }
  }

  if (*end == 'f' && *(end + 1) == '\0') {
    size_t pos = input.find('.');
    if (pos != std::string::npos && pos != input.length() - 2) {
      return FLOAT;
    }
  }
  if (*end == '\0') {
    size_t pos = input.find('.');
    if (pos != std::string::npos && pos != input.length() - 1) {
      return DOUBLE;
    } else {
      return INT;
    }
  }
  return INVALID;
}

void ScalarConverter::printConversion(char c) {
  std::cout << "Char: ";
  if (!std::isprint(c)) {
    std::cout << "Non displayable" << '\n';
  } else {
    std::cout << "'" << c << "'" << '\n';
  }
}

void ScalarConverter::printConversion(int i) {
  std::cout << "Int: " << i << '\n';
}

void ScalarConverter::printConversion(float f) {
  std::cout << "Float: ";
  if (std::isnan(f)) {
    std::cout << "nanf\n";
  } else if (std::isinf(f)) {
    std::cout << (f > 0 ? "+inff" : "-inff") << '\n';
  } else {
    std::cout << std::fixed << std::setprecision(1) << f << 'f' << '\n';
  }
}

void ScalarConverter::printConversion(double d) {
  std::cout << "Double: ";
  if (std::isnan(d)) {
    std::cout << "nan\n";
  } else if (std::isinf(d)) {
    std::cout << (d > 0 ? "+inf" : "-inf") << '\n';
  } else {
    std::cout << std::fixed << std::setprecision(1) << d << '\n';
  }
}

void ScalarConverter::convert(std::string &input) {
  Type type = detectType(input);
  switch (type) {
    case CHAR: {
      char c = input[0];
      printConversion(c);
      printConversion(static_cast<int>(c));
      printConversion(static_cast<float>(c));
      printConversion(static_cast<double>(c));
      break;
    }
    case INT: {
      char *end;
      long l = std::strtol(input.c_str(), &end, 10);
      if (l < CHAR_MIN || l > CHAR_MAX) {
        std::cout << "Char: Impossible\n";
      } else {
        printConversion(static_cast<char>(l));
      }
      if (*end != '\0' || l < INT_MIN || l > INT_MAX) {
        std::cout << "Int: Impossible\n";
      } else {
        printConversion(static_cast<int>(l));
      }
      printConversion(static_cast<float>(l));
      printConversion(static_cast<double>(l));
      break;
    }
    case FLOAT: {
      float f = std::strtof(input.c_str(), NULL);
      if (f < CHAR_MIN || f > CHAR_MAX || std::isnan(f) || std::isinf(f)) {
        std::cout << "Char: Impossible\n";
      } else {
        printConversion(static_cast<char>(f));
      }
      if (f < INT_MIN || f > INT_MAX || std::isnan(f) || std::isinf(f)) {
        std::cout << "Int: Impossible\n";
      } else {
        printConversion(static_cast<int>(f));
      }
      printConversion(f);
      printConversion(static_cast<double>(f));
      break;
    }
    case DOUBLE: {
      double d = std::strtod(input.c_str(), NULL);
      if (d < CHAR_MIN || d > CHAR_MAX || std::isnan(d) || std::isinf(d)) {
        std::cout << "Char: Impossible\n";
      } else {
        printConversion(static_cast<char>(d));
      }
      if (d < INT_MIN || d > INT_MAX || std::isnan(d) || std::isinf(d)) {
        std::cout << "Int: Impossible\n";
      } else {
        printConversion(static_cast<int>(d));
      }
      printConversion(static_cast<float>(d));
      printConversion(d);
      break;
    }
    case INVALID:
      std::cout << "Invalid input" << '\n';
      break;
    default:
      std::cout << "Invalid input" << '\n';
  }
}