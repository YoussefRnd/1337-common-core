/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:48:22 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/03 05:12:00 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

enum Type {
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
  INVALID
};

class ScalarConverter {
  private:
    // Constructors
    ScalarConverter();
    
    // Destructor
    ~ScalarConverter();
    
    // Copy Constructor
    ScalarConverter(const ScalarConverter &src);

    // Copy Assignment Operator
    ScalarConverter &operator=(const ScalarConverter &src);
    
  public:
    static void convert(std::string &input);
    static Type detectType(const std::string &input);
    static void printConversion(char c);
    static void printConversion(int i);
    static void printConversion(float f);
    static void printConversion(double d);
};