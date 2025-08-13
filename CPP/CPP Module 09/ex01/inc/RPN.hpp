/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:32:32 by yboumlak          #+#    #+#             */
/*   Updated: 2025/06/30 17:20:33 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

class RPN {
  public:
    RPN();
    RPN(const RPN &other);
    ~RPN();
    RPN &operator=(const RPN &other);

    std::stack<int> getOperands() const;
    std::vector<std::string> split(const std::string &str, char delimiter);
    bool isOperator(const std::string &token);
    bool isNumber(const std::string &token);
    bool evaluate(const std::vector<std::string> &tokens);

  private:
    std::stack<int> operands;
};